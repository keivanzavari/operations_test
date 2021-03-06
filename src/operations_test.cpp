#include <rtt/TaskContext.hpp>
#include <rtt/Component.hpp>
#include <rtt/Service.hpp>

#include <vector>

class OperationsTest : public RTT::TaskContext
{
public:
    std::string getMyName() {
        return getName();
    }

    
    OperationsTest(const std::string &name)
        : RTT::TaskContext(name)
    {
        this->addOperation("getMyName", &OperationsTest::getMyName, this)
        .doc("get name");
        this->addOperation("getOwnerName", &OperationsTest::getOwnerName, this)
        .doc("Returns the name of the owner of this object.");
    }

    ~OperationsTest()
    {}

    bool configureHook() {

        return true;
    }

    bool startHook()
    {
        return true;
    }

    void stopHook()
    {
    }

    void updateHook()
    {
    }

    std::vector<std::string> getOwnerName() {
        double d = this->getPeriod();
        // std::string t  = this->getOwner();
        std::vector<std::string> names;
        names.resize(2);
        for (unsigned int i=0; i<names.size(); ++i)
            names[i] = getName();
        RTT::log(RTT::Debug) << "Hi you just called me!!" << RTT::endlog();

        RTT::Logger::In in(this->getName());
        RTT::log(RTT::Info) << "another log!! "<< RTT::endlog();
        return names; ///this->getOwner()
    }
    // std::string OperationsTest::testOP(){
    
    //     return this->getOwner(); //->getPeerList();
    // }

    // std::string getOwnerName() {
    //     return getOwner()->getName();
    // }
private:

};


ORO_CREATE_COMPONENT(OperationsTest)

