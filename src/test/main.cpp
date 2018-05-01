#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test Suite
//#define VERBOSE

#include <boost/test/unit_test.hpp>
#include <smartcashapi/smartcashapi.h>
#include <smartcashapi/exception.h>

#define NO_THROW(METHOD)                    \
  try {                                     \
    (METHOD);                               \
  } catch (SmartcashException& e) {           \
    BOOST_REQUIRE_MESSAGE(false, e.what()); \
  }

#define NO_THROW_EXCEPT(METHOD, EXCEPTION)        \
  try {                                           \
    (METHOD);                                     \
  } catch (SmartcashException& e) {                 \
    std::stringstream err;                                        \
    err << "Error (" << e.getCode() << "): " << e.getMessage();   \
    BOOST_REQUIRE_MESSAGE(e.getCode() == (EXCEPTION), err.str()); \
    BOOST_WARN_MESSAGE(false, err.str());         \
    return;                                       \
  }

struct MyFixture {

	std::string username;
	std::string password;
	std::string address;
	int port;

	SmartcashAPI smart;

     MyFixture()
     : username("Ulysses"),
       password("Random"),
       address("127.0.0.1"),
       port(9679),
       smart(username, password, address, port)
     { }
     ~MyFixture() { }
};


BOOST_GLOBAL_FIXTURE(MyFixture);
