#include <iostream>
#include <string.h>

class Task
{
protected:
    char id[5];
public:
    Task() {}
    Task(char* id) { strcpy(this->id, id); }
    Task(const Task& t) { strcpy(this->id, t.id); }
    virtual int getOrder() = 0; char* getID() { return this->id; }
    inline virtual void print() = 0;
    ~Task() {}
};

inline bool operator == (Task* cmp1, Task& cmp2) noexcept { return (strcmp(cmp1->getID(), cmp2.getID()) == 0 && cmp1->getOrder() == cmp2.getOrder()); }

class TimedTask : public Task
{
private:
    int var{ int() };
public:
    TimedTask() : Task() {}
    TimedTask(char* id, int var) : Task(id) { this->var = var; }
    TimedTask(TimedTask& tt) : Task(tt.id) { this->var = tt.var; }
    int getOrder() noexcept { return this->var; }
    void print() { std::cout << "TT->" << this->id << ":" << this->getOrder() << std::endl; }
    ~TimedTask() {}
};

class PriorityTask : public Task
{
private:
    int var{ int() };
public:
    PriorityTask() : Task() {}
    PriorityTask(char* id, int var) : Task(id) { this->var = var; }
    PriorityTask(PriorityTask& pt) : Task(pt.id) { this->var = pt.var; }
    int getOrder() noexcept { return this->var; }
    void print() { std::cout << "PT->" << this->id << ":" << this->getOrder() << std::endl; }
    ~PriorityTask() {}
};

void _sort(Task** ptr_arr, int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = i + 1; j < n - 1; j++) {
            if (ptr_arr[i]->getOrder() > ptr_arr[j]->getOrder()) {
                Task* tmp = ptr_arr[i]; ptr_arr[i] = ptr_arr[j]; ptr_arr[j] = tmp;
            }
        }
    }
}

void scheduled_timed_tasks(Task** ptr_arr, int n, int var) {
    _sort(ptr_arr, n); for (unsigned int i = 0; i < n; i++) { if (dynamic_cast<PriorityTask*>(ptr_arr[i]) == NULL && ptr_arr[i]->getOrder() < var) { ptr_arr[i]->print(); } }
}

void scheduled_priority_tasks(Task** ptr_arr, int n, int var) {
    _sort(ptr_arr, n); for (unsigned int i = 0; i < n; i++) { if (dynamic_cast<TimedTask*>(ptr_arr[i]) == NULL && ptr_arr[i]->getOrder() < var) { ptr_arr[i]->print(); } }
}

int main()
{
    int testCase, n; std::cin >> testCase;

    if (testCase == 0) {
        std::cin >> n; Task** tasks; tasks = new Task * [n];

        for (unsigned int i = 0; i < n; i++) {
            char id[5]; int timeOrPriority, type; std::cin >> type >> id >> timeOrPriority;
            if (type == 0) { tasks[i] = new TimedTask(id, timeOrPriority); }
            else { tasks[i] = new PriorityTask(id, timeOrPriority); }
        }

        std::cout << "SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10" << std::endl; scheduled_priority_tasks(tasks, n, 10);
    }

    else if (testCase == 1) {
        std::cin >> n; Task** tasks; tasks = new Task * [n];

        for (unsigned int i = 0; i < n; i++) {
            char id[5]; int timeOrPriority, type;
            std::cin >> type >> id >> timeOrPriority;
            if (type == 0) { tasks[i] = new TimedTask(id, timeOrPriority); }
            else { tasks[i] = new PriorityTask(id, timeOrPriority); }
        }

        std::cout << "SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50" << std::endl; scheduled_timed_tasks(tasks, n, 50);
    }

    else {
        TimedTask* tt1 = new TimedTask("11", 10); TimedTask* tt2 = new TimedTask("11", 11); TimedTask* tt3 = new TimedTask("11", 11);
        PriorityTask* pp1 = new PriorityTask("aa", 10); PriorityTask* pp2 = new PriorityTask("11", 10);

        std::cout << (tt1 == (*tt2)) << std::endl << (tt2 == (*tt3)) << std::endl << (pp1 == (*pp2)) << std::endl << (pp2 == (*tt1)) << std::endl;
    }

    return 0;
}
