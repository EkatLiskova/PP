#include <iostream>
#include "mpi.h"
using namespace std;

int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	if (world_rank == 0) {
		int send_number = 111;
		MPI_Send(&send_number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else if (world_rank == 1) {
		int recv_number = NULL;
		MPI_Recv(&recv_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Hello to process 1 from process 0! Recieved number: " << recv_number << endl;
	}

	MPI_Finalize();
	return 0;
}