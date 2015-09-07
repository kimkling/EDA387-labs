/********************************************************* -- SOURCE -{{{1- */
/** Translate host name into IPv4
 *
 * Resolve IPv4 address for a given host name. The host name is specified as
 * the first command line argument to the program.
 *
 * Build program:
 *  $ gcc -Wall -g -o resolve <file>.cpp
 */
/******************************************************************* -}}}1- */

#include <stdio.h>
#include <stddef.h>

#include <assert.h>
#include <limits.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

//--//////////////////////////////////////////////////////////////////////////
//--    local declarations          ///{{{1///////////////////////////////////

void print_usage( const char* aProgramName );

//--    local config                ///{{{1///////////////////////////////////

/* HOST_NAME_MAX may be missing, e.g. if you're running this on an MacOS X
 * machine. In that case, use MAXHOSTNAMELEN from <sys/param.h>. Otherwise
 * generate an compiler error.
 */
#if !defined(HOST_NAME_MAX)
#	if defined(__APPLE__)
#		include <sys/param.h>
#		define HOST_NAME_MAX MAXHOSTNAMELEN
#	else  // !__APPLE__
#		error "HOST_NAME_MAX undefined!"
#	endif // ~ __APPLE__
#endif // ~ HOST_NAME_MAX

//--    main()                      ///{{{1///////////////////////////////////
int main( int aArgc, char* aArgv[] )
{
    // Check if the user supplied a command line argument.
    if( aArgc != 2 )
    {
        print_usage( aArgv[0] );
        return 1;
    }

    // The (only) argument is the remote host that we should resolve.
    const char* remoteHostName = aArgv[1];

    // Get the local host's name (i.e. the machine that the program is
    // currently running on).
    const size_t kHostNameMaxLength = HOST_NAME_MAX+1;
    char localHostName[kHostNameMaxLength];

    if( -1 == gethostname( localHostName, kHostNameMaxLength ) )
    {
        perror( "gethostname(): " );
        return 1;
    }

    // Print the initial message
    printf( "Resolving `%s' from `%s':\n", remoteHostName, localHostName );

    // sockaddr sock = {.sa_family = AF_INET};
    struct addrinfo addr = {.ai_family = AF_UNSPEC, .ai_socktype = SOCK_STREAM, .ai_protocol = IPPROTO_TCP};
    struct addrinfo *res, *rp;

    getaddrinfo(remoteHostName, NULL, &addr, &res);

    char *dst4, *dst6;

    dst4 = (char*) malloc(INET_ADDRSTRLEN);
    dst6 = (char*) malloc(INET6_ADDRSTRLEN);

    for(rp = res; rp != NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            sockaddr_in *addr_in = (sockaddr_in *) rp->ai_addr;
            inet_ntop(AF_INET, &addr_in->sin_addr.s_addr, dst4, INET_ADDRSTRLEN);
            printf("IPv4: '%s'\n", dst4);
        } else {
            sockaddr_in6 *addr_in = (sockaddr_in6 *) rp->ai_addr;
            inet_ntop(AF_INET6, &addr_in->sin6_addr.__u6_addr, dst6, INET6_ADDRSTRLEN);
            printf("IPv6: '%s'\n", dst6);
        }
    }

    freeaddrinfo(res);

    // Ok, we're done. Return success.
    return 0;
}


//--    print_usage()               ///{{{1///////////////////////////////////
void print_usage( const char* aProgramName )
{
    fprintf( stderr, "Usage: %s <hostname>\n", aProgramName );
}

//--///}}}1/////////////// vim:syntax=cpp:foldmethod=marker:ts=4:noexpandtab:
