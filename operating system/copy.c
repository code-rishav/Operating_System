#include <stdio.h> // for printf()
#include <unistd.h> // for open close read and write
#include <fcntl.h> // for for accessing file modes

int main(){
    char c; // the address of this variable will act as a buffer to be read from input and written to output
    int fd_in; // file descriptor of iput file
    int fd_out; // file descriptor of output file
    fd_in=open("input.txt", O_RDONLY); // open() accepts the filename and flag. O_RDONLY tells that
    if (fd_in==-1)                     // file is to be opened in read-only mode. open() returns -1 if error occurs,returns the file descriptor otherwise
    {
        printf("Error opening input file.\n");
        close(fd_in);
	    return 0;
    }
    
    fd_out=open("output.txt", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    // O_WRONLY tells that file is to be opened in write mode. If file does not exist then,
    // new file will be created (O_CREAT). Next argument specifies the permissions for the file
    // S_IRWXU allows user to read, write and execute the file. S_IRWXG allows group to read,
    //write and execute the file. S_IRWXO allows others to read, write and execute the file.
    if (fd_out==-1)
    {
        printf("Error opening output file.\n");
        close(fd_in);
        close(fd_out);
        return 0;
    }
    int w; // will define the status of write
    int r=read(fd_in, &c, 1); // defines the status of read
    while (r!=0) // read() accepts the file descriptor of the file to be read from, the buffer where the data will be stored, and 
    {                            // the size of bytes to be read. It returns -1 if error occurs and 0 at the end of file.
        if (r==-1)
        {
            printf("Error reading from the file.\n");
            break;
        }
        w=write(fd_out, &c, 1);  //similar parameters and behaviour as read
        if (w==-1)
        {
            printf("Error writing to the file.\n");
            break;
        }
        r=read(fd_in, &c, 1);
    }
    
    close(fd_in);
    close(fd_out);
    return 0;
}
