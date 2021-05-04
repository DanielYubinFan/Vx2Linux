int socket(int domain,int type,int protocol);

STATUS bind(int s, struct sockaddr* name, int namelen);

STATUS listen(int s, int backlog);

int accept(int s, struct sockaddr * addr, int* addrlen);

STATUS connect(int s, struct sockaddr * name, int namelen);

STATUS shutdown(int s, int how);
/* how 0:receives disallowed;1:sends disallowed;2:sends and receives disallowed */

int sendto(int s, caddr_t buf,/* pointer to data buffer */
int bufLen, int flags, /* flags to underlying protocols */

struct sockaddr * to, int tolen
/* length of to sockaddr */
);

int send(int s, const char* buf, int bufLen, int flags);

int sendmsg(int sd, struct msghdr* mp, int flags);

int recvfrom
(
int
s,
/* socket to receive from */
char *
buf,
/* pointer to data buffer */
int
bufLen, /* length of buffer */
int
flags,
/* flags to underlying protocols */

struct sockaddr * from,
/* where to copy sender's addr */
int *
pFromLen /* value/result length of from */
);
