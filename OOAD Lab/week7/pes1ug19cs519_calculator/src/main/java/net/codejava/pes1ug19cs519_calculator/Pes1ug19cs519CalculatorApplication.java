package net.codejava.pes1ug19cs519_calculator;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.DBCursor;
import static com.mongodb.client.model.Filters.eq;
import java.util.List;
import org.bson.Document;
import org.bson.json.JsonObject;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import static org.springframework.core.convert.TypeDescriptor.collection;


@SpringBootApplication
public class Pes1ug19cs519CalculatorApplication {

	public static void main(String[] args) {
            SpringApplication.run(Pes1ug19cs519CalculatorApplication.class, args);
	}

}
