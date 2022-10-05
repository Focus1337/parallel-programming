#ifndef PARALLPROG_HOMEWORKS_H
#define PARALLPROG_HOMEWORKS_H
namespace Homeworks {
    class Homework3 {
    public:
        static void ParallelCalculationBasic(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size);
        static void ParallelCalculationTapeSeparation(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size);
        static void ParallelCalculationBlock(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size);
    };

    class Homework2 {
    private:
        static void VectorsAdditionParallel();

        static void VectorsAdditionSequentially();

        static void MatrixMultiplyParallel();

        static void MatrixMultiplySequentially();

    public:
        static void Execute();
    };

    class Homework1 {
    public:
        static void FirstParallelProgram();
    };

} // Homeworks

#endif //PARALLPROG_HOMEWORKS_H
