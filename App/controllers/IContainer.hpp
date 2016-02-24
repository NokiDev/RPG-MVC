//
// Created by Noki, Timothé Van Deputte on 22/02/2016.
//

#ifndef RPG_MVC_ICONTAINER_HPP
#define RPG_MVC_ICONTAINER_HPP


class IContainer {
public:
    virtual IContainer(){};



private:
    virtual bool subControllerExist() const =0;
    virtual bool viewExist() const = 0;

};


#endif //RPG_MVC_ICONTAINER_HPP