#include <iostream>
#include <Windows.h>
#include "mpi.h"
using namespace std;

int main(int argc, char* argv[]) {
    int size;
    MPI_Init(&argc, &argv);
    int world_rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    if (world_rank == 0) {
        int number = 15;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if (world_rank == 1) {
        int recieved_num = 100;
        MPI_Recv(&recieved_num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
            MPI_STATUS_IGNORE);

        cout << "Hello to 1 process from 0 process, recieved number: " << recieved_num << endl;
    }
    MPI_Finalize();

    return 0;
}