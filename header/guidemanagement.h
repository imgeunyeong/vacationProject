#ifndef __GUIDEMANAGEMENT_H_
#define __GUIDEMANAGEMENT_H_
#include "database.h"
#include <string>
#include <unistd.h>

class guide_management : public Database
{
    private:
        std::string guide_name;
    public:
        void show_guide_list();
        void add_guide();
        void work_guide();
        void delete_guide();
};
#endif