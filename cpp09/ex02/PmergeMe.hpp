#include <vector>
#include <list>
#include <limits>
#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <cstdlib>

class merge
{
    public:
        merge( void );
        merge( int argc, char *argv[] );
        ~merge( void );
        merge( merge const &src );
        merge &operator=( merge const &rhs );
        void create_lists(int argc, char *argv[]);
        void sort( void );

    private:
        void printVec( void );
        void printLis( void );
        void mergeSortVec(std::vector<int> &vector);
        void mergeSortLis(std::list<int> &lis);
        void printTimeVals(void);
        std::vector<int> _vec;
        std::list<int> _lis;
        double timeVec;
        double timeLis;
};
