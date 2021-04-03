#include <iostream>
#include <unistd.h>
#include <math.h>
#include "mpi.h"
#include "check.h"
#include "collect.h"

//Each process that calls this function, creates an array of
//that contains rows/numP rows. Each row has cols elements.
//These are the source arrays.  In addition, Process 0 creates
//a destination array that will be used to gather all rows.
//Each process needs to initialize their source array so that
//when the Gather is called, each element in the process 0 
//destination array will be equal to its index: dest[i] = i
void gatherRows(int rows, int cols, int myId, int numP)
{
    int * dest = NULL;
    //Process 0 needs to create an array that is big enough to hold
    //all rows


    //process 0 checks to see if the gather worked
    if (!myId)
    {
        std::cout << "Checking to see if Gather of rows succeeded\n";
        checkGatherRows(dest, rows, cols, myId);
    }
}

//Each process that calls this function, creates an array of
//that contains rows/numP rows. Each row has cols elements.
//These are the source arrays.  In addition, each process creates
//a destination array that will be used to gather all rows.
//Each process needs to initialize their source array so that
//when the Allgather is called, each element in the 
//destination array will be equal to its index: dest[i] = i
void allGatherRows(int rows, int cols, int myId, int numP)
{
    int * dest = NULL;


    //here's the check
    if (!myId)
    {   
        std::cout << "Checking to see if All Gather of rows succeeded\n";
    }
    //every process should have received an identical array
    checkAllGatherRows(dest, rows, cols, myId);
}

//This function will call Gather so that process 0 will collect the structs
//of all processes.
//
//Hint: You'll need to create an MPI Datatype
void gatherStructs(int myId, int numP)
{
    int * dest = NULL; 
    int i;
    char letters[12] = {'g', 'r', 'e', 'e', 't', 'i', 'n', 'g', 's', '!', '!', 0};
    struct sendStruct
    {
        char sletters[12];
        int rank;
    } sendThis;

    for (i = 0; i < 12; i++) sendThis.sletters[i] = letters[i];
    sendThis.rank = myId;

    //Create an MPI Datatype

    //Process 0 needs to destination array that is large enough to hold all structs
    //from all processes


    //All of the struct values need to be at process 0
    if (!myId)
    {
        std::cout << "Checking to see if Gather of structs succeeded\n";
        checkGatherStructs(dest, myId, numP);
    }
}

