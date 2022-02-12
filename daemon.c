#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

static char *pid_file_name = NULL;
static int pid_fd = -1;

static void daemonize()
{
    int fd;
    pid_t pid = 0;

    // Fork off the parent process
    pid = fork();

    // Error ocurred
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // Child becomes session leader
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    // Ignore signal sent from child to parent process
    signal(SIGCHLD, SIG_IGN);

    // Set new file permissions
    umask(0);

    // Change the working to the root directory
    chdir("/");

    // Close all open file descriptors
    for (fd = sysconf(_SC_OPEN_MAX); fd > 0; fd--) {
        close(fd);
    }

    // Reopen stdin, stdout, stderr
    stdin = fopen("/dev/null", "r");
	stdout = fopen("/dev/null", "w+");
	stderr = fopen("/dev/null", "w+");

    // Try to write PID of daemin to lockfile
    if (pid_file_name != NULL){
        
        char str[256];
        pid_fd = open(pid_file_name, O_RDWR | O_CREAT, 0640);

        if (pid_fd < 0) {
            // can't open lockfile
            exit(EXIT_FAILURE);
        }

        if (lockf(pid_fd, F_TLOCK, 0) < 0) {
            //can't lock file
            exit(EXIT_FAILURE);
        }

        // Get current PID
        sprintf(str, "%d\n", getpid());

        // Write PID to lockfile
        write(pid_fd, str, strlen(str));

    }
}

int main(int argc, char *argv[]){

    daemonize();

    return EXIT_SUCCESS;
}