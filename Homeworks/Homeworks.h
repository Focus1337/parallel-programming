#ifndef PARALLPROG_HOMEWORKS_H
#define PARALLPROG_HOMEWORKS_H
namespace Homeworks {

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
