#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

/* gethostbyname accepts a host name as a parameter and returns a hostent structure:

struct  hostent {
    char    *h_name;        // official name of host
	char    **h_aliases;    // alias list
	int     h_addrtype;     // host address type
	int     h_length;       // length of address
	char    **h_addr_list;  // list of addresses from name server
};

If all goes well, the h_addr_list will contain a list of IP addresses. There may be more
than one IP addresses for a host. In practice, you should be able to use any of the addresses
or you may want to pick one that matches a particular subnet. You may want to check that
(h_addrtype == AF_INET) and (h_length == 4) to ensure that you have a 32-bit IPv4 address. */

/* paddr: print the IP address in a standard decimal dotted format */
void paddr(unsigned char *a)
{
    printf("%d.%d.%d.%d\n", a[0], a[1], a[2], a[3]);
}

int main(int argc, char **argv) {
    struct hostent *hp;
    char *host = "google.com";
    int i;

    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "could not obtain address of %s\n", host);
        return 0;
    }
    
    // We'll be lazy here and just use the first address in the list.
    for (i=0; hp->h_addr_list[i] != 0; i++)
        paddr((unsigned char*) hp->h_addr_list[i]);

    exit(0);
}