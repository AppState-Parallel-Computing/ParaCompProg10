#include <iostream>
#include <unistd.h>
#include <math.h>
#include "mpi.h"
#include "check.h"
#include "distribute.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

//This function uses Send and Recv to distribute the rows of the data array
//in a blocked way using numP - 1 Sends.  
//data contains rows * cols ints. Each process receives rows/numP consecutive rows.
void distributeRowsSendRecv(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //TO DO:
    //Each process will receive its data in the array pointed to by dest.
    //You need to dynamically allocate an array that is big enough for
    //a process to hold its share of the data (but not too big).
    //Process 0 makes numP - 1 calls to Send.
    //All other processes make one call to Recv.

    //Here's the check
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output 
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Recv succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);

    //TO DO: Delete dynamically allocated data.
}

//This function uses Isend and Irecv to distribute the rows of the data array
//in a blocked way using numP - 1 Isends.  
//data contains rows * cols ints. Each process receives rows/numP rows.
void distributeRowsIsendIrecv(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //TO DO:
    //Each process will receive its data in the array pointed to by dest.
    //You need to dynamically allocate an array that is big enough for
    //a process to hold its share of the data (but not too big).
    //Process 0 makes numP - 1 calls to Isend. 
    //All other processes make one call to Irecv and one call to Wait.


    //Here's the check
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output in case you've added print statements
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Irecv succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);

    //TO DO: Delete dynamically allocated data.
}

//This function uses Scatter to distribute the rows of the data array
//in a blocked way.  
//data contains rows * cols ints. Each process receives rows/numP rows.
void distributeRowsScatter(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //TO DO:
    //Each process will receive its data in the array pointed to by dest.
    //You need to dynamically allocate an array that is big enough for
    //a process to hold its share of the data (but not too big).
    //Then call Scatter.

    //Here's the check
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output in case you've added print statements
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Scatter succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);

    //TO DO: Delete dynamically allocated data.
}

//This function uses Send and Recv to distribute the cols of the data array
//in a blocked way using numP - 1 Sends.  
//data contains rows * cols. Each process gets cols/numP columns.
//
//HINT: create a new MPI Datatype
void distributeColsSendRecv(int * data, int rows, int cols, int myId, int numP)
{   
    int * dest = NULL;
    
    //TO DO:
    //Each process will receive its data in the array pointed to by dest.
    //You need to dynamically allocate an array that is big enough for
    //a process to hold its share of the data (but not too big).
    //You need to define and create an MPI Datatype using Create_vector.
    //Process 0 needs to call Send numP - 1 times.
    //All other processes need to call Recv.
    
    //Here's the check
    if (!myId) 
        std::cout << "Checking to see if the distribution of columns using Recv succeeded\n"; 
    MPI::COMM_WORLD.Barrier();
    checkDistributeCols(dest, rows, cols, myId, numP);

    //TO DO: Delete dynamically allocated data.
}

