#include "MoneyGuard.h"

void MoneyGuard::serialize() // ������ ���� ������������� � ����
{
    std::ofstream file{ "DataBase.bin", std::ios::binary };
    if (file.is_open())
    {
        int users_count = m_users_list.size();
        file.write((char*)&users_count, sizeof(int));
        for (int i = 0; i < users_count; i++)
        {
            std::string login = m_users_list[i].m_login;
            int login_size = login.size();
            const char* login_data = login.data();
            file.write((char*)&login_size, sizeof(int));
            file.write(login_data, login_size);
            std::string password = m_users_list[i].m_password;
            int password_size = password.size();
            const char* password_data = password.data();
            file.write((char*)&password_size, sizeof(int));
            file.write(password_data, password_size);
            int categories_count = m_users_list[i].m_categories.size();
            file.write((char*)&categories_count, sizeof(int));
            for (int j = 0; j < categories_count; j++)
            {
                std::string category_name = m_users_list[i].m_categories[j].m_category_name;
                int category_name_size = category_name.size();
                const char* category_name_data = category_name.data();
                file.write((char*)&category_name_size, sizeof(int));
                file.write(category_name_data, category_name_size);
                int events_count = m_users_list[i].m_categories[j].m_events.size();
                file.write((char*)&events_count, sizeof(int));
                for (int k = 0; k < events_count; k++)
                {
                    std::string event_name = m_users_list[i].m_categories[j].m_events[k]->m_event_name;
                    int event_name_size = event_name.size();
                    const char* event_name_data = event_name.data();
                    file.write((char*)&event_name_size, sizeof(int));
                    file.write(event_name_data, event_name_size);
                    std::string creation_time = m_users_list[i].m_categories[j].m_events[k]->m_creation_time;
                    int creation_time_size = creation_time.size();
                    const char* creation_time_data = creation_time.data();
                    file.write((char*)&creation_time_size, sizeof(int));
                    file.write(creation_time_data, creation_time_size);
                    float event_cash = m_users_list[i].m_categories[j].m_events[k]->m_cash;
                    file.write((char*)&event_cash, sizeof(float));
                }
            }
        }
        file.close();
    }
}

void MoneyGuard::deserialize() // ���������� ���� ������������� �� �����
{
    std::ifstream file{ "DataBase.bin", std::ios::binary };
    if (file.is_open())
    {
        int users_count = m_users_list.size();
        file.read((char*)&users_count, sizeof(int));
        for (int i = 0; i < users_count; i++)
        {
            User user;
            int login_size;
            file.read((char*)&login_size, sizeof(int));
            char* login_data = new char[login_size + 1] {};
            file.read(login_data, login_size);
            user.m_login = login_data;
            delete[] login_data;
            int password_size;
            file.read((char*)&password_size, sizeof(int));
            char* password_data = new char[password_size + 1] {};
            file.read(password_data, password_size);
            user.m_password = password_data;
            delete[] password_data;
            int categories_count;
            file.read((char*)&categories_count, sizeof(int));
            for (int j = 0; j < categories_count; j++)
            {
                Category category;
                int category_name_size;
                file.read((char*)&category_name_size, sizeof(int));
                char* category_name_data = new char[category_name_size + 1] {};
                file.read(category_name_data, category_name_size);
                category.m_category_name = category_name_data;
                delete[] category_name_data;
                int events_count;
                file.read((char*)&events_count, sizeof(int));
                user.m_categories.push_back(category);
                for (int k = 0; k < events_count; k++)
                {
                    int event_name_size;
                    file.read((char*)&event_name_size, sizeof(int));
                    char* event_name_data = new char[event_name_size + 1] {};
                    file.read(event_name_data, event_name_size);
                    int creation_time_size;
                    file.read((char*)&creation_time_size, sizeof(int));
                    char* creation_time_data = new char[creation_time_size + 1] {};
                    file.read(creation_time_data, creation_time_size);
                    float event_cash;
                    file.read((char*)&event_cash, sizeof(float));
                    if (event_cash > 0)
                    {
                        user.m_categories[j].m_events.push_back(new Profit{ event_name_data, event_cash });
                    }
                    else
                    {
                        user.m_categories[j].m_events.push_back(new Expense{ event_name_data, event_cash });
                    }
                    delete[] event_name_data;
                    delete[] creation_time_data;
                }
            }
            m_users_list.push_back(user);
        }
        file.close();
    }
}


MoneyGuard::~MoneyGuard()
{
    for (int i = 0; i < m_current_user.m_categories.size(); i++)
    {
        for (int j = 0; j < m_current_user.m_categories[i].m_events.size(); j++)
        {
            delete m_current_user.m_categories[i].m_events[j];
        }
    }
}

void MoneyGuard::start(User& a_user) // ������� ����� ��� ������ ��������
{
    m_current_user = a_user;
    std::cout << "������, " << m_current_user.m_login << "! ����� �� ������ ������� ���� �� ��������� ��������:" << '\n';
    bool flag = true;
    while (flag)
    {
        std::cout << "A - ���������;" << '\n';
        std::cout << "B - ������� �������;" << '\n';
        std::cout << "C - ����� �� ��������." << '\n';
        std::cout << " --> ";
        char choice;
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 'A':
        case 'a':
            {
                categories();
                break;
            }
        case 'B':
        case 'b':
            {
                history();
                break;
            }
        case 'C':
        case 'c':
            {
                flag = false;
                break;
            }
        default:
            {
                std::cout << "������������ ����! ���������� ������." << '\n';
                break;
            }
        }
    }
}

void MoneyGuard::show_categories()
{
    std::cout << "��� ����������: " << '\n';
    if (m_current_user.m_categories.size() == 0)
    {
        std::cout << "������ ����." << '\n';
    }
    else
    {
        for (int i = 0; i < m_current_user.m_categories.size(); i++)
        {
            std::cout << i + 1 << ". " << m_current_user.m_categories[i].m_category_name << ((i == m_current_user.m_categories.size() - 1) ? '.' : ';') << '\n';
        }
    }
}

void MoneyGuard::categories() // ����������� ��� ������� ���������
{
    bool flag = true;
    while (flag)
    {
        show_categories();
        std::cout << "A - ������� ���������;" << '\n';
        std::cout << "B - �������� ���������;" << '\n';
        std::cout << "C - ������� ���������." << '\n';
        std::cout << "D - ��������� �������." << '\n';
        std::cout << " --> ";
        char choice;
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 'A':
        case 'a':
            {
                choice_category();
                break;
            }
        case 'B':
        case 'b':
            {
                add_category();
                break;
            }
        case 'C':
        case 'c':
            {
                remove_category();
                break;
            }
        case 'D':
        case 'd':
            {
                flag = false;
                break;
            }
        default:
            {
                std::cout << "������������ ����! ���������� ������." << '\n';
                break;
            }
        }
    }

}

void MoneyGuard::choice_category() // ����� ���������
{
    while (true)
    {
        show_categories();
        std::cout << "�������� ����� ��������� �� ������ ������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
        std::cout << " --> ";
        int choice;
        std::cin >> choice;
        system("cls");
        if (choice == 0)
        {
            return;
        }
        if (choice > 0 && choice < m_current_user.m_categories.size() + 1)
        {
            --choice;
            events(choice);
        }
        else
        {
            std::cout << "������������ ����! ���������� ������." << '\n';
        }
    }
}

void MoneyGuard::show_events(int a_index)
{
    std::cout << "��� ������� ��������� " << m_current_user.m_categories[a_index].m_category_name << ": " << '\n';
    if (m_current_user.m_categories[a_index].m_events.size() == 0)
    {
        std::cout << "������ ����." << '\n';
    }
    else
    {
        for (int i = 0; i < m_current_user.m_categories[a_index].m_events.size(); i++)
        {
            std::cout << i + 1 << ". ";
            m_current_user.m_categories[a_index].m_events[i]->show();
            std::cout << ((i == m_current_user.m_categories[a_index].m_events.size() - 1) ? '.' : ';') << '\n';
        }
    }
}

void MoneyGuard::events(int a_index) // ����������� ��� ������� �������
{
    bool flag = true;
    while (flag)
    {
        show_events(a_index);
        std::cout << "A - �������� �������;" << '\n';
        std::cout << "B - ������� �������." << '\n';
        std::cout << "C - ��������� �������." << '\n';
        std::cout << " --> ";
        char choice;
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 'A':
        case 'a':
            {
                add_event(a_index);
                break;
            }
        case 'B':
        case 'b':
            {
                remove_event(a_index);
                break;
            }
        case 'C':
        case 'c':
            {
                flag = false;
                break;
            }
        default:
            {
                std::cout << "������������ ����! ���������� ������." << '\n';
                break;
            }
        }
    }
}

void MoneyGuard::add_event(int a_index) // �������� �������
{
    bool flag = true;
    while (flag)
    {
        std::cout << "�� ������ �������� �����(������� E) ��� �������(������� P)?\n�������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
        std::cout << " --> ";
        char choice;
        std::cin >> choice;
        system("cls");
        if (choice == '0')
        {
            return;
        }
        switch (choice)
        {
        case 'E':
        case 'e':
            {
                std::cout << "������� �������� ��� ������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
                std::cout << " --> ";
                std::string event_name;
                std::cin.ignore();
                std::getline(std::cin, event_name);
                system("cls");
                if (event_name == "0")
                {
                    return;
                }
                float cash;
                while (true)
                {
                    std::cout << "������� �� ���������? ������� ����� � AZN (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
                    std::cout << " --> ";
                    std::cin >> cash;
                    system("cls");
                    if (cash == 0)
                    {
                        return;
                    }
                    if (cash <= 0)
                    {
                        std::cout << "����� ������ ���� �������������! ������� ������." << '\n';
                    }
                    break;
                }
                m_current_user.m_categories[a_index].m_events.push_back(new Expense{ event_name, -cash });
                std::cout << "������� ������� �������." << '\n';
                flag = false;
                break;
            }
        case 'P':
        case 'p':
            {
                std::cout << "������� �������� ��� ������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
                std::cout << " --> ";
                std::string event_name;
                std::cin.ignore();
                std::getline(std::cin, event_name);
                system("cls");
                float cash;
                while (true)
                {
                    std::cout << "������� �� ����������? ������� ����� � AZN (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
                    std::cout << " --> ";
                    std::cin >> cash;
                    system("cls");
                    if (cash == 0)
                    {
                        return;
                    }
                    if (cash <= 0)
                    {
                        std::cout << "����� ������ ���� �������������! ������� ������." << '\n';
                    }
                    break;
                }
                m_current_user.m_categories[a_index].m_events.push_back(new Profit{ event_name, cash });
                std::cout << "������� ������� �������." << '\n';
                flag = false;
                break;
            }
        default:
            {
                std::cout << "������������ ����! ���������� ������." << '\n';
                break;
            }
        }
    }
}

void MoneyGuard::remove_event(int a_index) // ������� �������
{
    while (true)
    {
        show_events(a_index);
        std::cout << "�������� ����� ������� �� ������ ������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
        std::cout << " --> ";
        int choice;
        std::cin >> choice;
        system("cls");
        if (choice == 0)
        {
            return;
        }
        if (choice > 0 && choice < m_current_user.m_categories[a_index].m_events.size() + 1)
        {
            --choice;
            auto iterator = m_current_user.m_categories[a_index].m_events.begin();
            iterator = iterator + choice;
            delete m_current_user.m_categories[a_index].m_events[choice];
            m_current_user.m_categories[a_index].m_events.erase(iterator);
            std::cout << "������� ������� �������." << '\n';
            break;
        }
        else
        {
            std::cout << "������������ ����! ���������� ������." << '\n';
        }
    }
}

void MoneyGuard::add_category() // �������� ���������
{
    bool flag = true;
    while (flag)
    {
        std::cout << "������� �������� ��� ��������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
        std::cout << " --> ";
        std::string category_name;
        std::cin.ignore();
        std::getline(std::cin, category_name);
        system("cls");
        if (category_name == "0")
        {
            return;
        }
        flag = false;
        for (auto& i : m_current_user.m_categories)
        {
            if (category_name == i.m_category_name)
            {
                std::cout << "��������� � ����� ��������� ��� ����������! ���������� ������." << '\n';
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            Category new_category{ category_name };
            m_current_user.m_categories.push_back(new_category);
            std::cout << "��������� ������� �������." << '\n';
        }
    }
}

void MoneyGuard::remove_category() // ������� ���������
{
    while (true)
    {
        show_categories();
        std::cout << "�������� ����� ��������� �� ������ ������� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
        std::cout << " --> ";
        int choice;
        std::cin >> choice;
        system("cls");
        if (choice == 0)
        {
            return;
        }
        if (choice > 0 && choice < m_current_user.m_categories.size() + 1)
        {
            --choice;
            auto iterator = m_current_user.m_categories.begin();
            iterator = iterator + choice;
            for (int i = 0; i < iterator->m_events.size(); i++)
            {
                delete m_current_user.m_categories[choice].m_events[i];
            }
            m_current_user.m_categories.erase(iterator);
            std::cout << "��������� ������� �������." << '\n';
            break;
        }
        else
        {
            std::cout << "������������ ����! ���������� ������." << '\n';
        }
    }
}

void MoneyGuard::history() // ������� �������
{
    while (true)
    {
        std::cout << "������� ���� �������:" << '\n';
        if (m_current_user.m_categories.size() == 0)
        {
            std::cout << "��������� ���." << '\n';
        }
        else
        {
            for (int i = m_current_user.m_categories.size() - 1; i >= 0; i--)
            {
                std::cout << "��������� " << m_current_user.m_categories[i].m_category_name << ":\n";
                if (m_current_user.m_categories.size() == 0)
                {
                    std::cout << "������� � ���� ��������� ���." << '\n';
                }
                else
                {
                    for (int j = m_current_user.m_categories[i].m_events.size() - 1; j >= 0; j--)
                    {
                        std::cout << "| ";
                        m_current_user.m_categories[i].m_events[j]->show();
                        std::cout << "\n���� �������� ����� �������: ";
                        std::cout << m_current_user.m_categories[i].m_events[j]->m_creation_time;
                        std::cout << ((i == 0) ? "." : ";") << '\n';
                    }
                }
            }
        }
        std::cout << "������� clear ��� ������� ��� 0 ����� ��������� �����. ������ ������ �� ����, ���� �� �������� �������, ��� ������� ��������� ���� ����������� ������������." << '\n';
        std::cout << " --> ";
        std::string choice;
        std::cin >> choice;
        system("cls");
        if (choice == "0")
        {
            return;
        }
        if (choice == "clear")
        {
            clear_history();
            break;
        }
        else
        {
            std::cout << "������������ ����! ���������� ������." << '\n';
        }
    }
}

void MoneyGuard::clear_history() // �������� �������
{
    for (int i = 0; i < m_current_user.m_categories.size(); i++)
    {
        for (int j = 0; j < m_current_user.m_categories[i].m_events.size(); j++)
        {
            delete m_current_user.m_categories[i].m_events[j];
        }
        m_current_user.m_categories[i].m_events.clear();
    }
    std::cout << "������� ������� �������." << '\n';
}

std::vector<User> MoneyGuard::get_users_list() // �������� ������ ���� �������������
{
    deserialize();
    return m_users_list;
}

void MoneyGuard::add_user() // �������� � ���� ������ ������ ������������
{
    m_users_list.push_back(m_current_user);
    serialize();
}

void MoneyGuard::update_user() // �������� ������������ � ���� ������
{
    for (auto& i : m_users_list)
    {
        if (i.m_login == m_current_user.m_login)
        {
            i = m_current_user;
            break;
        }
    }
    serialize();
}


