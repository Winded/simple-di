# Simple DI - simple dependency injection container for C++

Simple DI provides a dependency injection container that is very simple.
It supports singleton lifecycle only, and has a straightforward interface.

 - `get<T>` returns an instance for given type parameter as shared_ptr. If an instance does not exist, it is created. Type must not be pure-virtual and it must contain a constructor that takes parameter `const std::shared_ptr<smdi::container>&`
 - `get_existing<T>` returns an existing instance for given type parameter, or `nullptr` if none exists
 - `set<T>` can be used to manually assign an instance to a type. This is what you should use if you want dependencies that are either third-party or pure-virtual. This is also useful for tests to replace implementations with mocks.

Note that the container holds shared_ptr references to the instances it creates, so if you wish to hold a reference to the container itself, do so using weak_ptr.
