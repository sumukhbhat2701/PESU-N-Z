package net.codejava.pes1ug19cs519_calculator;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class Pes1ug19cs519CalculatorApplicationTests {
        @Autowired
        private WebController controller;
        
	@Test
	void contextLoads() {
               Assertions.assertNotNull(controller);
	}

}
