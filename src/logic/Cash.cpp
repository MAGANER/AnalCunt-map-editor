#include "Cash.h"


Cash::Cash(string path)
{
    this->path = path;
}
Cash::~Cash()
{
}

string Cash::get(int elem_id)
{
    return data[elem_id];
}

void Cash::load()
{
    ifstream loader(path);

    if(!loader)
    {
        cout<<"can not load cash!"<<endl;
    }


    string file_data = "";
    while(!loader.eof())
    {
        loader>>file_data;
        data.push_back(file_data);
    }
    loader.close();

    data.clear();// because data is saved in file
}
void Cash::save()
{
    ofstream savior;

    savior.open(path);
    if(savior.fail())
    {
        cout<<"can not save file!"<<endl;
    }
    savior.clear();//because save new data

    auto data_elem = data.begin();
    while(data_elem != data.end())
    {
        savior<<*data_elem;
        savior<<endl;
        ++data_elem;
    }

    savior.close();
}
void Cash::add(string new_data)
{
    data.push_back(new_data);
}


bool Cash::_is_empty()
{
    return !data.empty();
}








