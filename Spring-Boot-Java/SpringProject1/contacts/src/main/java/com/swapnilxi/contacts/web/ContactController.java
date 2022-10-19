package com.ltp.contacts.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.ltp.contacts.pojo.Contact;
import com.ltp.contacts.service.ContactService;
import com.ltp.contacts.service.ContactServiceImpl;

//@Controller
@RestController
public class ContactController {
    
    @Autowired
    private ContactService contactService;

    @GetMapping("/contact/{id}")
    //@ResponseBody
    public ResponseEntity<Contact> getContact(@PathVariable String id) {
        Contact contact = contactService.getContactById(id);
        return new ResponseEntity<>(contact, HttpStatus.OK);
    }
    
    @PostMapping("/contact")
    public ResponseEntity<HttpStatus> createContact(@RequestBody Contact contact){
        contactService.saveContact(contact);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }



}
