#include "pch.h"
#include "CppUnitTest.h"
#include "../LowestCommonAncestor/LowestCommonAncestor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            //Root Node
            Node* root = newNode(0);

            //Tier 1
            root->left = newNode(1);
            root->right = newNode(2);

            //Tier 2
            root->left->left = newNode(3);
            root->left->right = newNode(4);

            //Tier 2
            root->right->left = newNode(5);
            root->right->right = newNode(6);

            //Tier 3
            root->left->left->left = newNode(7);
            root->left->left->right = newNode(8);
            root->left->right->left = newNode(9);
            root->left->right->right = newNode(10);

            //Tier 3
            root->right->left->left = newNode(11);
            root->right->left->right = newNode(12);
            root->right->right->left = newNode(13);
            root->right->right->right = newNode(14);

            Assert::AreEqual(lowestCommonAncestor(root, 11, 13), 2);
            Assert::AreEqual(lowestCommonAncestor(root, 9, 10), 4);
            Assert::AreEqual(lowestCommonAncestor(root, 3, 4), 1);
            Assert::AreEqual(lowestCommonAncestor(root, 7, 8), 3);
            Assert::AreEqual(lowestCommonAncestor(root, 11, 12), 5);
		}
	};
}
