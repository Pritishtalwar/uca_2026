#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

const char *fileType(mode_t mode) {
    if (S_ISREG(mode)) return "Regular File";
    if (S_ISDIR(mode)) return "Directory";
    if (S_ISCHR(mode)) return "Character Device";
    if (S_ISBLK(mode)) return "Block Device";
    if (S_ISFIFO(mode)) return "FIFO/Pipe";
    if (S_ISLNK(mode)) return "Symbolic Link";
    if (S_ISSOCK(mode)) return "Socket";
    return "Unknown";
}

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);
    printf("File Type:            %s\n", fileType(st.st_mode));
    printf("Permissions:          %04o\n", st.st_mode & 0777);
    printf("File Size:            %ld bytes\n", (long)st.st_size);
    printf("Hard Links Count:     %ld\n", (long)st.st_nlink);
    printf("Owner (UID):          %d\n", st.st_uid);
    printf("Group (GID):          %d\n", st.st_gid);
    printf("Last Access Time:     %s", ctime(&st.st_atime));
    printf("Last Modification:    %s", ctime(&st.st_mtime));
    printf("Status Change Time:   %s", ctime(&st.st_ctime));

    return 0;
}
