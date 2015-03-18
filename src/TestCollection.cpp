#include "../inc/TestCollection.h"

namespace Frisk
{
	/**
	* Initializes a new instance of TestCollection.
	*/
	TestCollection::TestCollection()
	{

	}

	/**
	* Destroys this instance of TestCollection.
	*/
	TestCollection::~TestCollection()
	{

	}

	/**
	* Adds a test to the test collection.
	* @param func The function that defines the tests.
	* @param name The name of the test, if it is not initialized or named in the function.
	*/
	void TestCollection::addTest(std::function<void(Frisk::Test &)> func, const std::string &name)
	{
		TestCollection::TestFuncPair pair;
		pair.func = func;
		pair.test.initialize(name);

		this->tests.push_back(pair);
	}

	/**
	* Runs the given tests and returns a list of the test objects.
	* @param failfast If true, then the tests will be run only until the first failure.
	* @returns A list of Test objects.
	*/
	std::list<Frisk::Test> TestCollection::runTests(bool failfast, Reporter *reporter)
	{
		std::list<Frisk::Test> result;
		if (reporter != nullptr)
			reporter->onStart(*this);

		std::list<TestCollection::TestFuncPair>::iterator it = this->tests.begin();
		while (it != this->tests.end())
		{
			if (reporter != nullptr)
				reporter->onPreRun((*it).test);

			(*it).func((*it).test);
			result.push_back((*it).test);

			if (reporter != nullptr)
				reporter->onPostRun((*it).test);

			// only quit if failfast AND the test is NOT pending.
			if (failfast && ((*it).test.getFailureCount() != 0) && ((*it).test.getOption(FRISK_OPTION_PENDING) == 0))
				break;

			it++;
		}

		if (reporter != nullptr)
			reporter->onComplete();

		return result;
	}
}