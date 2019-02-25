#ifndef EXAMPLE_CLASS
#define EXAMPLE_CLASS 1

    class ExampleClass{
    public:
        ExampleClass();

        static int numOfObjects;
        //Static function can only access static variables. It does not know about member vars
        static void printNumOfObjects();

        //Member functions can access static symbols however:
        void tryToAccessStatic();

    private:

    };

#endif
