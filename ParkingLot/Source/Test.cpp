#include <gtest/gtest.h>
#include "Manager.h"
#include "ParkedNum.h"
#include "VacantNum.h"
#include "VacantRatio.h"

Car car1("津AB1234");
Car car2("津CD1234");
Car car3("津EF1234");
Car car4("津GH1234");
Car car5("津IJ1234");
Car car6("津KL1234");

TEST(PrakingLotTest,ParkedNumCarTest)
{
	Ticket  ticket1("Admin1", "A", 1, "津AB1234");
	Ticket  ticket2("Admin1", "A", 2, "津CD1234");
	Ticket  ticket3("Admin1", "B", 1, "津EF1234");
	Ticket  ticket4("Admin1", "B", 2, "津GH1234");
	Ticket  ticket5("Admin1", "B", 3, "津IJ1234");
	Ticket  ticket6("Admin1", "A", 1, "津KL1234");

	ParkingLotProperty p[2] = {{"A",2},{"B",3}};
	AdminProperty a1 = {"Admin1", 2, p, new ParkedNum()};
	Admin admin(a1);

	Ticket t1=admin.ParkCar(car1);
	EXPECT_TRUE(t1==ticket1);
	Ticket t2=admin.ParkCar(car2);
	EXPECT_TRUE(t2==ticket2);
	Ticket t3=admin.ParkCar(car3);
	EXPECT_TRUE(t3==ticket3);
	Ticket t4=admin.ParkCar(car4);
	EXPECT_TRUE(t4==ticket4);
	Ticket t5=admin.ParkCar(car5);
	EXPECT_TRUE(t5==ticket5);
	Ticket t6=admin.ParkCar(car6);
	EXPECT_TRUE(t6== NULL_TICKET);

	Car c1=admin.GetCar(t1);
	EXPECT_TRUE(c1==car1);
	Car c2=admin.GetCar(t2);
	EXPECT_TRUE(c2==car2);
	Car c3=admin.GetCar(t3);
	EXPECT_TRUE(c3==car3);
	Car c4=admin.GetCar(t4);
	EXPECT_TRUE(c4==car4);
	Car c5=admin.GetCar(t5);
	EXPECT_TRUE(c5==car5);
	Car c6=admin.GetCar(t6);
	EXPECT_TRUE(c6==NULL_CAR);

}

TEST(PrakingLotTest,VacanctNumCarTest)
{
	Ticket  ticket1("Admin1", "B", 1, "津AB1234");
	Ticket  ticket2("Admin1", "A", 1, "津CD1234");
	Ticket  ticket3("Admin1", "B", 2, "津EF1234");
	Ticket  ticket4("Admin1", "A", 2, "津GH1234");
	Ticket  ticket5("Admin1", "B", 3, "津IJ1234");
	Ticket  ticket6("Admin1", "A", 1, "津KL1234");

	ParkingLotProperty p[2] = {{"A",2},{"B",3}};
	AdminProperty a1 = {"Admin1", 2, p, new VacantNum()};
	Admin admin(a1);

	Ticket t1=admin.ParkCar(car1);
	EXPECT_TRUE(t1==ticket1);
	Ticket t2=admin.ParkCar(car2);
	EXPECT_TRUE(t2==ticket2);
	Ticket t3=admin.ParkCar(car3);
	EXPECT_TRUE(t3==ticket3);
	Ticket t4=admin.ParkCar(car4);
	EXPECT_TRUE(t4==ticket4);
	Ticket t5=admin.ParkCar(car5);
	EXPECT_TRUE(t5==ticket5);
	Ticket t6=admin.ParkCar(car6);
	EXPECT_TRUE(t6== NULL_TICKET);

	Car c1=admin.GetCar(t1);
	EXPECT_TRUE(c1==car1);
	Car c2=admin.GetCar(t2);
	EXPECT_TRUE(c2==car2);
	Car c3=admin.GetCar(t3);
	EXPECT_TRUE(c3==car3);
	Car c4=admin.GetCar(t4);
	EXPECT_TRUE(c4==car4);
	Car c5=admin.GetCar(t5);
	EXPECT_TRUE(c5==car5);
	Car c6=admin.GetCar(t6);
	EXPECT_TRUE(c6==NULL_CAR);
}

TEST(PrakingLotTest,VacanctRatioCarTest)
{
	Ticket  ticket1("Admin1", "A", 1, "津AB1234");
	Ticket  ticket2("Admin1", "B", 1, "津CD1234");
	Ticket  ticket3("Admin1", "B", 2, "津EF1234");
	Ticket  ticket4("Admin1", "A", 2, "津GH1234");
	Ticket  ticket5("Admin1", "B", 3, "津IJ1234");
	Ticket  ticket6("Admin1", "A", 1, "津KL1234");

	ParkingLotProperty p[2] = {{"A",2},{"B",3}};
	AdminProperty a1 = {"Admin1", 2, p, new VacantRatio()};
	Admin admin(a1);

	Ticket t1=admin.ParkCar(car1);
	EXPECT_TRUE(t1==ticket1);
	Ticket t2=admin.ParkCar(car2);
	EXPECT_TRUE(t2==ticket2);
	Ticket t3=admin.ParkCar(car3);
	EXPECT_TRUE(t3==ticket3);
	Ticket t4=admin.ParkCar(car4);
	EXPECT_TRUE(t4==ticket4);
	Ticket t5=admin.ParkCar(car5);
	EXPECT_TRUE(t5==ticket5);
	Ticket t6=admin.ParkCar(car6);
	EXPECT_TRUE(t6== NULL_TICKET);

	Car c1=admin.GetCar(t1);
	EXPECT_TRUE(c1==car1);
	Car c2=admin.GetCar(t2);
	EXPECT_TRUE(c2==car2);
	Car c3=admin.GetCar(t3);
	EXPECT_TRUE(c3==car3);
	Car c4=admin.GetCar(t4);
	EXPECT_TRUE(c4==car4);
	Car c5=admin.GetCar(t5);
	EXPECT_TRUE(c5==car5);
	Car c6=admin.GetCar(t6);
	EXPECT_TRUE(c6==NULL_CAR);
}


TEST(PrakingLotTest,ManagerCarTest)
{
	ParkingLotProperty p[2] = {{"A",2},{"B",3}};
	AdminProperty a1 = {"Admin1", 2, p, new ParkedNum()};
	AdminProperty a2 = {"Admin2", 2, p, new VacantNum()};
	AdminProperty a3 = {"Admin3", 2, p, new VacantRatio()};
	AdminProperty a[3]={a1,a2,a3};
	ManagerProperty m={3,a};
	Manager manager(m);

	Ticket t1=manager.ParkCar(car1);
	Ticket t2=manager.ParkCar(car2);
	Ticket t3=manager.ParkCar(car3);
	Ticket t4=manager.ParkCar(car4);
	Ticket t5=manager.ParkCar(car5);
	Ticket t6=manager.ParkCar(car1);
	Ticket t7=manager.ParkCar(car2);
	Ticket t8=manager.ParkCar(car3);
	Ticket t9=manager.ParkCar(car4);
	Ticket t10=manager.ParkCar(car5);
	manager.Print();
	Ticket t11=manager.ParkCar(car1);
	Ticket t12=manager.ParkCar(car2);
	Ticket t13=manager.ParkCar(car3);
	Ticket t14=manager.ParkCar(car4);
	Ticket t15=manager.ParkCar(car5);
	Ticket t16=manager.ParkCar(car1);

	Car c1=manager.GetCar(t1);
	EXPECT_TRUE(c1==car1);
	Car c2=manager.GetCar(t2);
	EXPECT_TRUE(c2==car2);
	Car c3=manager.GetCar(t3);
	EXPECT_TRUE(c3==car3);
	Car c4=manager.GetCar(t4);
	EXPECT_TRUE(c4==car4);
	Car c5=manager.GetCar(t5);
	EXPECT_TRUE(c5==car5);
	Car c6=manager.GetCar(t6);
	EXPECT_TRUE(c6==car1);
	Car c7=manager.GetCar(t7);
	EXPECT_TRUE(c7==car2);
	Car c8=manager.GetCar(t8);
	EXPECT_TRUE(c8==car3);
	Car c9=manager.GetCar(t9);
	EXPECT_TRUE(c9==car4);
	Car c10=manager.GetCar(t10);
	EXPECT_TRUE(c10==car5);
	Car c11=manager.GetCar(t11);
	EXPECT_TRUE(c11==car1);
	Car c12=manager.GetCar(t12);
	EXPECT_TRUE(c12==car2);
	Car c13=manager.GetCar(t13);
	EXPECT_TRUE(c13==car3);
	Car c14=manager.GetCar(t14);
	EXPECT_TRUE(c14==car4);
	Car c15=manager.GetCar(t15);
	EXPECT_TRUE(c15==car5);
	Car c16=manager.GetCar(t16);
	EXPECT_TRUE(c16==NULL_CAR);


}
int main(int argc,char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
