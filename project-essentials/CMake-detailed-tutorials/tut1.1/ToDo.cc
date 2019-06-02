#include "ToDo.h"


ToDo::ToDo()
{
}

ToDo::~ToDo()
{
}

//Return vector size
size_t ToDo::size() const
{
    return this_tasks.size();
}

//Add to vector
void ToDo::addTask(
    const std::string& task
)
{
    this_tasks.push_back(task);
}

//Get vector value
std::string ToDo::getTask(
    size_t index
) const
{
    if (index < this_tasks.size())
    {
        return this_tasks[index];
    }
    else
    {
        return "";
    }
}

