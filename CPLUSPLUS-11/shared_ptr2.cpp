#include <iostream>
#include <memory>

int main () 
{
    auto deleter = [](int*p)
    {
         delete p;
    };

    std::shared_ptr<int> foo (new int,deleter);
    std::cout << "use_count: " << foo.use_count() << '\n';
    return 0;                       
}
