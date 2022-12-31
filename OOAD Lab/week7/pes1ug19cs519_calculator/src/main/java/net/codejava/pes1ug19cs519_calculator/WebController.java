/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package net.codejava.pes1ug19cs519_calculator;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PostMapping;
import com.google.gson.Gson;

/**
 * @author sumukhbhat2701 - PES1UG19CS519
 */


@Controller
public class WebController {

    @PostMapping("/result")
    public String calculateResult(Model model, String op1, String op2, String op)
    {
                System.out.println("Calculating result...");
                Expression e = new Expression(op, op1, op2);
                
                
                // Database
                MongoClient client = MongoClients.create();

               MongoDatabase db = client.getDatabase("calculate");
               MongoCollection col = db.getCollection("calculate");
              
               Document profile = (Document)col.find(new Document("op1", op1).append("op",op).append("op2",op2)).first(); 
               
               if(profile != null)
               {
                   String k = profile.toJson();
               Gson gson = new Gson();
                Expression cache = gson.fromJson(k, Expression.class);
                   model.addAttribute("result", cache.op1 + " " + cache.op + " " + cache.op2 + " = "+ cache.res);
                   System.out.println("From DB, result:"+ cache.op1 + " " + cache.op + " " + cache.op2 + " = "+ cache.res);
                   return "result.html";
               }
               String res = e.calculate();
               System.out.println(res);
                Document sampleDoc = new Document("op1", op1).append("op",op).append("op2",op2).append("res", res);
                col.insertOne(sampleDoc);
                System.out.println(res);
                model.addAttribute("result", op1+" "+op+" "+op2+" = "+res);
                return "result.html";
    }
}
