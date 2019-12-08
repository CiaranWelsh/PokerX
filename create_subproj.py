import os
import argparse


def modify_main_cmake(project_name):
    return """
# "{0}" project
########################################
set({0}_DIR ${{PROJECT_SOURCE_DIR}}/{0})
set({0} ON)
message("{0} project is:\t\t ${{{0}}}")
if (${{{0}}})
    add_subdirectory(${{{0}_DIR}})
endif ()
""".format(project_name)


def create_sub_cmake(project_name):
    return """
cmake_minimum_required(VERSION 3.0)

add_executable({0} ${{{0}_DIR}}/source/{0}.cpp)
target_sources(
        {0} PUBLIC ${{{0}_DIR}}/source/{0}.cpp
)

""".format(project_name)

def source_boilerplate():
    return """

#include <iostream>
using namespace std;

int main(){
    cout << "hello world" << endl;
    
    return 0;
};
"""

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('project_name', type=str)
    args = parser.parse_args()

    project_name = args.project_name
    wd = os.path.dirname(__file__)

    project_location = os.path.join(wd, args.project_name)
    main_cmake_location = os.path.join(wd, 'CMakeLists.txt')
    sub_cmake_location = os.path.join(project_location, 'CMakeLists.txt')
    project_source_dir = os.path.join(project_location, 'source')
    project_source_file = os.path.join(project_source_dir, project_name + '.cpp')

    if not os.path.isdir(project_location):
        os.makedirs(project_location)

    if not os.path.isdir(project_source_dir):
        os.makedirs(project_source_dir)

    if not os.path.isfile(sub_cmake_location):
        with open(sub_cmake_location, 'w') as f:
            f.write(create_sub_cmake(project_name))

    with open(main_cmake_location, 'r') as f:
        current_cmake_text = f.read()

    main_cmake_new_text = modify_main_cmake(project_name)
    if not main_cmake_new_text in current_cmake_text:
        with open(main_cmake_location, 'a') as f:
            f.write(main_cmake_new_text)

    if not os.path.isfile(project_source_file):
        with open(project_source_file, 'w') as f:
            f.write(source_boilerplate())



