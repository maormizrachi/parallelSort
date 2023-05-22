#include "sort.hpp"
#include "io/input.h"
#include "io/output.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::vector<int> vector;
    getVector("input/" + std::to_string(rank) + ".in", vector);

    double time = MPI_Wtime();

    // the sorting itself
    sort(vector);

    double took = MPI_Wtime() - time;
    double longest;
    MPI_Reduce(&took, &longest, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    printAllArraysSizes(vector); // print only sizes
    printToFile("output/" + std::to_string(rank) + ".out", vector);

    if(rank == 0)
    {
        std::cout << "Time:" << longest << " seconds" << std::endl;
    }

    MPI_Finalize();
    return EXIT_SUCCESS;
}
