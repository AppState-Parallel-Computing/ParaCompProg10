#include <iostream>
#include <unistd.h>
#include <math.h>
#include "mpi.h"
#include "check.h"
#include "distribute.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

//This function uses Send and Recv to distribute the rows of the data array
//in a blocked way using numP - 1 Sends.  Thus process 1 gets rows numP ... 2*numP - 1, 
//process 2 gets rows 2*numP ... 3*numP - 1, process 3 gets rows 3*numP .. 4*numP - 1,
//etc.
void distributeRowsSendRecv(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //Only process 0 will do the send

    //Here's the check
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output in case you've added print statements
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Recv succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);
}

//This function uses Isend and Irecv to distribute the rows of the data array
//in a blocked way using numP - 1 Isends.  Thus process 1 gets rows numP ... 2*numP - 1, 
//process 2 gets rows 2*numP ... 3*numP - 1, process 3 gets rows 3*numP .. 4*numP - 1
//etc.
void distributeRowsIsendIrecv(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //Only process 0 will do the send


    //Don't continue until all processes have received their data. You
    //are not allowed to call Barrier to do this.


    //Here's the check
    //Your code should also work without this barrier.  Be sure to test that.
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output in case you've added print statements
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Irecv succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);
}

//This function uses Scatter to distribute the rows of the data array
//in a blocked way.  Thus process 1 gets rows numP ... 2*numP - 1, process 2 
//gets rows 2*numP ... 3*numP - 1, process 3 gets rows 3*numP .. 4*numP - 1
//etc.
void distributeRowsScatter(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;


    //Here's the check
    MPI::COMM_WORLD.Barrier();  //barrier used to try to get neater output in case you've added print statements
    if (!myId) 
        std::cout << "Checking to see if the distribution of rows using Scatter succeeded\n";
    checkDistributeRows(dest, rows, cols, myId, numP);
}

//This function uses Send and Recv to distribute the cols of the data array
//in a blocked way using numP - 1 Sends.  Thus process 1 gets columns numP ... 2*numP - 1,
//process 2 gets columns 2*numP ... 3*numP - 1, process 3 gets columns 3*numP .. 4*numP - 1
//etc.
//
//HINT: create a new MPI Datatype
void distributeColsSendRecv(int * data, int rows, int cols, int myId, int numP)
{   
    int * dest = NULL;
    
    //Only process 0 will do the send
    
    //Here's the check
    if (!myId) 
        std::cout << "Checking to see if the distribution of columns using Recv succeeded\n"; 
    MPI::COMM_WORLD.Barrier();
    checkDistributeCols(dest, rows, cols, myId, numP);
}

//This function uses Scatter to distribute the cols of the data array
//in a blocked way.  Thus process 1 gets columns numP ... 2*numP - 1, process 2 
//gets columns 2*numP ... 3*numP - 1, process 3 gets columns 3*numP .. 4*numP - 1
//etc.
//Hint: Consecutive chunks in the array need to be scattered to consecutive
//      processes, thus for this to work, you'll need to create a new array
//      to contain a reordering of the values in the data array
void distributeColsScatter(int * data, int rows, int cols, int myId, int numP)
{  
    int * dest = NULL;


    //Here's the check
    if (!myId)
        std::cout << "Checking to see if the distribution of columns using Scatter succeeded\n";
    MPI::COMM_WORLD.Barrier();
    checkDistributeCols(dest, rows, cols, myId, numP);
}

//This function uses Send and Recv to distribute the blocks of the data array
//to the processes using numP - 1 Sends.  The input array of size rows and cols 
//is divided into gridDim by gridDim blocks where gridDim is equal to sqrt(numP).
//block(i, j) in the input array is sent to process i * gridDim + j.
//
//Hint: You'll need to create a new MPI Datatype
void distributeBlocksSendRecv(int * data, int rows, int cols, int myId, int numP)
{
    int gridDim = sqrt(numP);
    if (gridDim * gridDim != numP)
    {
       if (!myId)
       {
           std::cout << RED << "Error: " << RESET 
                     << "In order to distribute blocks, the number of processes must be square\n";
           std::cout << "Exiting distributeBlocksSendRecv\n";
       }
       return;
    }
    int * dest = NULL;
    int i, j;

    //Only process 0 will do the send

    //Here's the check
    MPI::COMM_WORLD.Barrier();
    if (!myId)
        std::cout << "Checking to see if the distribution of blocks using Recv succeeded\n";
    checkDistributeBlocks(dest, rows, cols, myId, numP);
}

//This function uses Send and Recv to distribute the rows of the data array
//in a cyclic way using numP - 1 Sends.  Thus process i receives rows i, i + numP, 
//i + 2*numP, etc. 
//
//Hint: Create a new MPI Datatype
void distributeRowsCyclicSendRecv(int * data, int rows, int cols, int myId, int numP)
{
    int * dest = NULL;

    //Only process 0 will do the send

    //Here's the check
    MPI::COMM_WORLD.Barrier();
    if (!myId)
        std::cout << "Checking to see if the cyclic distribution of rows using Recv succeeded\n";
    checkDistributeCyclic(dest, rows, cols, myId, numP);
}

