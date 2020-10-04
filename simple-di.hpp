#pragma once

#include <memory>
#include <typeinfo>
#include <map>

namespace smdi
{
    class container : public std::enable_shared_from_this<container>
    {
    public:
        template<typename T>
        std::shared_ptr<T> get()
        {
            auto id = typeid(T).hash_code();
            auto instance = get_existing<T>();
            if (instance != nullptr)
            {
                return instance;
            }

            instance = std::make_shared<T>(shared_from_this());
            set(instance);
            return instance;
        }

        template<typename T>
        std::shared_ptr<T> get_existing()
        {
            auto id = typeid(T).hash_code();
            auto it = m_Instances.find(id);
            if (it != m_Instances.end())
            {
                return std::static_pointer_cast<T>((*it).second);
            }
            else
            {
                return nullptr;
            }
        }

        template<typename T>
        void set(const std::shared_ptr<T> &dep)
        {
            auto id = typeid(T).hash_code();
            m_Instances[id] = dep;
        }

    private:
        std::map<size_t, std::shared_ptr<void>> m_Instances;
    };
}
