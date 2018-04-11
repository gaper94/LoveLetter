template<typename T>
void GenericMsg::AddValue(const std::string& valueName, const T& value)
{
    auto& buff = m_valuesContainer[valueName];
    buff.Clear();
    buff << value;
}

template<typename T>
bool GenericMsg::GetValue(const std::string& valueName, T& value) const
{
    bool result = false;
    auto it = m_valuesContainer.find(valueName);
    if(it != m_valuesContainer.end())
    {
        Deserializer is;
        is.Load((*it).second.GetBuffer());
        is >> value;
        result = true;
    }
    return result;
}
