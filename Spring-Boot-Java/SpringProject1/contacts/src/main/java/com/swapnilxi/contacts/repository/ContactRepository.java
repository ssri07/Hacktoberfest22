package com.ltp.contacts.repository;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.springframework.stereotype.Repository;

import com.ltp.contacts.pojo.Contact;

@Repository
public class ContactRepository {
    
    private List<Contact> contacts = new ArrayList<>();
    // private List<Contact> contacts = Arrays.asList(new Contact("12", "jon Snow ", "99188292822"), new Contact ("24", "tyrion", "889383838"));
    // public List<Contact> getContacts() {
    //     return contacts;
    // }

  
    public List<Contact> getContacts() {
        return contacts;
    }

    public Contact getContact(int index) {
        return contacts.get(index);
    }

    public void saveContact(Contact contact) {
        contacts.add(contact);
    }

    public void updateContact(int index, Contact contact) { 
        contacts.set(index, contact); 
    }
    
    public void deleteContact(int index) {
        contacts.remove(index);
    }

}
