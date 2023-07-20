#include "PmergeMe.hpp"

merge::merge( int argc, char *argv[] )
{
    create_lists(argc, argv);
}

merge::~merge( void ) {}

merge::merge( merge const &src )
{
    this->_lis = src._lis;
    this->_vec = src._vec;
}

merge &merge::operator=( merge const &rhs )
{
    *this = rhs;
    return *this;
}

void merge::create_lists(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int val = atoi(argv[i]);
        _vec.push_back(val);
        _lis.push_back(val);
    }
}

void merge::sort( void )
{
    std::cout << "Before: ";
    printLis();
    struct timeval begin, end;
    long seconds;
    long microseconds;
    gettimeofday(&begin, 0);
    mergeSortVec(_vec);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    timeVec = seconds + microseconds * 0.000001;
    gettimeofday(&begin, 0);
    mergeSortLis(_lis);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    timeLis = seconds + microseconds * 0.000001;
    std::cout << "After: ";
    printVec();
    printTimeVals();
}

void merge::printVec( void )
{
    size_t i;
    for (i = 0; i < _vec.size() && i < 4; i++)
        std::cout << _vec[i] << " ";
    if (_vec.size() == 5)
        std::cout << _vec[i] << " ";
    else if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void merge::printLis( void )
{
    std::list<int>::iterator it;
    size_t i = 0;
    for (it = _lis.begin(); it != _lis.end() && i < 4; it++, i++)
        std::cout << *it << " ";
    if (_lis.size() == 5 )
        std::cout << *it << " ";
    else if (_lis.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void merge::printTimeVals( void)
{
    std::cout << std::fixed << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << " s" << std::endl;
    std::cout << "Time to process a range of " << _lis.size() << " elements with std::list : " << timeLis << " s" << std::endl;
}

void merge::mergeSortVec(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;
    std::vector<int> left, right;

    std::vector<int>::iterator mid = vec.begin();
    std::advance(mid, vec.size() / 2);
    left.insert(left.begin(), vec.begin(), mid);
    right.insert(right.begin(), mid, vec.end());
    vec.clear();
    mergeSortVec(left);
    mergeSortVec(right);

    std::vector<int>::iterator it_left = left.begin();
    std::vector<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
            vec.push_back(*it_left++);
        else
            vec.push_back(*it_right++);
    }
    vec.insert(vec.end(), it_left, left.end());
    vec.insert(vec.end(), it_right, right.end());
    left.erase(it_left, left.end());
    right.erase(it_right, right.end());
}

void merge::mergeSortLis(std::list<int> &lis)
{
    if (lis.size() <= 1)
        return;
    std::list<int> left, right;

    std::list<int>::iterator mid = lis.begin();
    std::advance(mid, lis.size() / 2);
    left.splice(left.begin(), lis, lis.begin(), mid);
    right.splice(right.begin(), lis, mid, lis.end());

    mergeSortLis(left);
    mergeSortLis(right);

    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
            lis.push_back(*it_left++);
        else
            lis.push_back(*it_right++);
    }
    lis.splice(lis.end(), left, it_left, left.end());
    lis.splice(lis.end(), right, it_right, right.end());
}
