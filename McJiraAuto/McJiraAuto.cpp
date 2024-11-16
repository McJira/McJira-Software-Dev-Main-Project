#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include "../McJira-Software-Dev-Main-Project/InputValidation.cpp"
#include "../McJira-Software-Dev-Main-Project/Player.cpp"
#include "../McJira-Software-Dev-Main-Project/Enemy.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace McJiraAutomatedTestProject
{
	TEST_CLASS(McJiraAutomatedTestProject)
	{
	public:

		// Player constructor
		//   Sets the initial health to a private instance variable maxHealth
		//   and sets the player coordinates (on an X,Y scale) to 0,0
		TEST_METHOD(ConstructorHelloAutoTest)
		{
			Player player;
			Logger::WriteMessage("Creating player instance & verifying initial settings\n");
			// Currently maxHealth is private, so can't directly access from here, hardcoding for now
			Assert::AreEqual(player.GetHealth(), 100, L"Initial health is not set correctly!");
			Assert::AreNotEqual(player.GetHealth(), 0, L"Intentional Failure checking initial health not equal to 100");

			// Better approach - add a setter to the player class to return the maxHealth - ie getMaxHealth()
			Logger::WriteMessage("Verify initial health setting is set to maxHealth\n");
			Assert::AreEqual(player.GetHealth(), 100, L"Initial health is not set correctly!");

			// To Do validate initial coordinates
		}

		// Player health
		//   several methods for dealing with health, no error checking implemented
		//   GetHealth() - returns current health setting -int to +int
		//   GainHealth(int) - adds the parameter to the current player health
		//   TakeDamaage(int) - subtracts the parameter from the current player health
		// will break this into two test cases
		//   One - current behavior - no error checking for min or max
		//   Second - if we implemented changes so health could go below zero, or above maxHealth
		TEST_METHOD(UnverifiedHealthTests) {
			Player player;
			Logger::WriteMessage("Take damage & verify health is maxHealth - damage\n");
			int damage = 50;
			player.TakeDamage(damage);
			Assert::AreEqual(player.GetHealth(), 100 - damage, L"Player damage not properly computed");

			Logger::WriteMessage("add back in some health & confirm, for grins go above maxHealth\n");
			int health = 75;
			player.GainHealth(health);
			Assert::AreEqual(player.GetHealth(), 100 - damage + health, L"Player health addition in error");

			Logger::WriteMessage("Reset health & Take more damage - excessive - go well below zero\n");
			damage = 10000000;
			player.SetInitialHealth();
			player.TakeDamage(damage);
			Assert::AreEqual(player.GetHealth(), 100 - damage, L"Player damage not properly computed for large damage");


			// print out final health
			std::string message = "Final health is " + std::to_string(player.GetHealth()) + "\n";
			Logger::WriteMessage(message.c_str());
		}

		// TBD test method
		// Let's say we confine health between zero & maxHealth
		// Idea is to create test cases that take damage > current health & verify health is greater than or equal to zero
		// and to gain health that would exceed maxHealth and confirm health is capped at maxHealth
		// 
		// Consider other enhancements to the player class - assuming you wanted to use it for "enemies" as well
		// set the maxHealth in an overloaded constructor
		// create a player name & description & starting room - also initialized in the constructor, which could be used
		// to place the enemy and reuse the player (maybe it becomes an entity) class
		// For example - Entity ogre ("Ogre", "Dirty, giant, beast of the underworld .....", 1, 1, 25)
		//   Places an orgre in location 1,1 with a starting health of 25
		TEST_METHOD(verifiedHealthTests) {
			Player player;
			Logger::WriteMessage("This will fail - take damage > maxHealth and verify >= 0\n");
			int damage = 100 + 1;
			player.TakeDamage(damage);
			std::string message = "After taking damage - health is " + std::to_string(player.GetHealth()) + "\n";
			Logger::WriteMessage(message.c_str());
			Assert::IsTrue(player.GetHealth() >= 0, L"Player health is less than zero");
		}

		// Test some enemy functionality
		// Create an enemy and see if it alive on creation
		TEST_METHOD(enemyLifeTests) {
			Enemy firstEnemy;  // should initialize enemy to no specific name & 25 health

			Logger::WriteMessage("First verify the enemy is actually alive\n");
			Assert::IsTrue(firstEnemy.isAlive(), L"Enemy expected to be alive, but is DEAD!");

			// Presumably - health is initialized to 25.0, verify this
			Logger::WriteMessage("First verify the enemy health is initialized to 25.0\n");
			Assert::AreEqual(firstEnemy.getHealth(), 25.0, L"Health is not what we expected, 25.0");
			Assert::AreNotEqual(firstEnemy.getHealth(), 0.0, L"Health is unexpected 0");

			// Kill this enemy
			Logger::WriteMessage("Do lots of damage to the enemy and verify it is dead\n");
			firstEnemy.EnemyTakeDamage(1000000);
			Assert::IsFalse(firstEnemy.isAlive(), L"Enemy was clobberted but is still alive!");
		}
	};
}
