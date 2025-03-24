#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
};

void displayMenu() {
    std::cout << "\n请选择一个选项:\n";
    std::cout << "1. 添加联系人\n";
    std::cout << "2. 查看所有联系人\n";
    std::cout << "3. 删除联系人\n";
    std::cout << "4. 退出\n";
}

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "\n请输入联系人的名字: ";
    std::cin.ignore(); // 忽略之前的换行符
    std::getline(std::cin, newContact.name);

    std::cout << "请输入联系人的电话号码: ";
    std::getline(std::cin, newContact.phone);

    contacts.push_back(newContact);
    std::cout << "联系人已成功添加。\n";
}

void viewContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "\n当前没有联系人。\n";
        return;
    }

    std::cout << "\n所有联系人:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". 名字: " << contacts[i].name << ", 电话: " << contacts[i].phone << "\n";
    }
}

void deleteContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "\n当前没有联系人可以删除。\n";
        return;
    }

    int index;
    viewContacts(contacts);
    std::cout << "请输入要删除的联系人编号: ";
    std::cin >> index;

    if (index > 0 && index <= static_cast<int>(contacts.size())) {
        contacts.erase(contacts.begin() + index - 1);
        std::cout << "联系人已成功删除。\n";
    } else {
        std::cout << "无效的编号，请重新输入。\n";
    }
}

int main() {
    std::vector<Contact> contacts;

    while (true) {
        displayMenu();
        int choice;
        std::cout << "您的选择: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                deleteContact(contacts);
                break;
            case 4:
                std::cout << "感谢使用，再见!\n";
                return 0;
            default:
                std::cout << "无效的选择，请重新输入。\n";
        }
    }

    return 0;
}


