#ifndef TODO_H
#define TODO_H

#include <string>
#include <vector>


class ToDo
{
public:
    ToDo();
    ~ToDo();
    
    //Method called in main function
    size_t size() const;

    //Both methods called in main function
    void addTask(const std::string& task);
    std::string getTask(size_t index) const;

private:
    //Used in ToDo.cc
    std::vector< std::string > this_tasks;
};

#endif // TODO_H
