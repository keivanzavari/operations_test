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
        // , sockfd_(0)
        // , port_(0)
        // , first_run_updatehook_(true)
    {
        // this->addProperty("port", port_);
        // this->addProperty("addr", addr_);
        this->addOperation("getMyName", &OperationsTest::getMyName, this)
        .doc("get name");
        this->addOperation("getOwnerName", &OperationsTest::getOwnerName, this)
        .doc("Returns the name of the owner of this object.");

        // fda_ = new FileDescriptorActivity(0);
        // this->setActivity(fda_);

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
        return names; ///this->getOwner()
    }
    // std::string OperationsTest::testOP(){
    //     RTT::log(RTT::Debug) << "Hi I am test OP" << RTT::endlog();
    //     return this->getOwner(); //->getPeerList();
    // }

    // std::string getOwnerName() {
    //     return getOwner()->getName();
    // }
private:
    std::string addr_;
    bool first_run_updatehook_;

};


ORO_CREATE_COMPONENT(OperationsTest)

