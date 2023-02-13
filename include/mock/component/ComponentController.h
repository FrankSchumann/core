#include <gmock/gmock.h>

#include "../../component/ComponentControllerIf.h"

namespace mock::core
{
	class ComponentController : public core::ComponentControllerIf
	{
	public:
		virtual ~ComponentController(){}

	    MOCK_METHOD ( void, create, ( std::string const &type, std::string const &name ), (override));
	    MOCK_METHOD (std::shared_ptr< core::ComponentIf >, get, ( std::string const &type, std::string const &name ), (const, override));
	    MOCK_METHOD (void, erase, ( std::string const &type, std::string const &name ), (override));
	    MOCK_METHOD (void, erase, ( std::string const &type ), (override));

	};
}
