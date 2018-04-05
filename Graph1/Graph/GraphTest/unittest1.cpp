#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph/vertex.h"
#include "../Graph/edge.h"
#include "../Graph/graph.h"
#include "../Graph/Nag��wek.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(VertexConstructor)
		{
			vertex ver("vertex");
			const std::string name = "vertex";
			Assert::AreEqual(ver.name,name);
			Assert::AreEqual(ver.visited, false);
			Assert::IsTrue(ver.edges.empty());
		
		}

		TEST_METHOD(EdgeWeightConstructor)
		{
			edge edge1(1);
			Assert::AreEqual(edge1.number, 1);
			Assert::AreEqual(edge1.weight, 0);

			edge edge2(1, 1);
			Assert::AreEqual(edge2.number, 1);
			Assert::AreEqual(edge2.weight, 1);
		}

		TEST_METHOD(VertexAddRemoveEdge)
		{
			vertex vertex("ver");
			vertex.addEdge(1);
			vertex.addEdge(10, 100);
			Assert::IsTrue(vertex.edges[0].number==1);
			Assert::IsTrue(vertex.edges[0].weight == 0);

			vertex.removeEdge(1);
			Assert::IsTrue(vertex.edges.size() == 1);
			Assert::IsTrue(vertex.edges[0].number == 1);
			Assert::IsTrue(vertex.edges[0].weight == 0);
		}

		TEST_METHOD(FindVertex)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			Assert::AreEqual(graph.findVertex("vertex0"), 0);
			Assert::AreEqual(graph.findVertex("vertex5"), 5);
			Assert::AreEqual(graph.findVertex("kasjd"), -1);
		}

		TEST_METHOD(RemoveVertex)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			graph.removeVertex("vertex1");
			graph.removeVertex("vertex3");
			Assert::IsFalse(graph.vertexInGraph[1].name == "vertex1");
			Assert::IsTrue(graph.vertexInGraph.size() == 4);
		}
		

		TEST_METHOD(connectUnoriented)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			graph.connectUnoriented("vertex0", "vertex1");
			graph.connectUnoriented("vertex5", "vertex2");

			Assert::IsTrue(graph.vertexInGraph[0].edges[0].number==1);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].number == 2);
			Assert::IsTrue(graph.vertexInGraph[0].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[3].edges.empty());
		}

		TEST_METHOD(connectUnorientedW)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			graph.connectUnoriented("vertex0", "vertex1",10);
			graph.connectUnoriented("vertex5", "vertex2",1);

			Assert::IsTrue(graph.vertexInGraph[0].edges[0].number == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].number == 2);
			Assert::IsTrue(graph.vertexInGraph[0].edges[0].weight == 10);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].weight == 1);
			Assert::IsTrue(graph.vertexInGraph[0].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[3].edges.empty());
		}

		TEST_METHOD(connectOriented)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			graph.connectUnoriented("vertex0", "vertex1");
			graph.connectUnoriented("vertex5", "vertex2");

			Assert::IsTrue(graph.vertexInGraph[0].edges[0].number == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].number == 2);
			Assert::IsTrue(graph.vertexInGraph[1].edges[0].number == 0);
			Assert::IsTrue(graph.vertexInGraph[2].edges[0].number == 5);

			Assert::IsTrue(graph.vertexInGraph[0].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[3].edges.empty());
		}

		TEST_METHOD(connectOrientedW)
		{
			graph graph;
			graph.addVertex("vertex0");
			graph.addVertex("vertex1");
			graph.addVertex("vertex2");
			graph.addVertex("vertex3");
			graph.addVertex("vertex4");
			graph.addVertex("vertex5");
			graph.connectUnoriented("vertex0", "vertex1", 10);
			graph.connectUnoriented("vertex5", "vertex2", 1);

			Assert::IsTrue(graph.vertexInGraph[0].edges[0].number == 1);
			Assert::IsTrue(graph.vertexInGraph[0].edges[0].weight == 10);
			Assert::IsTrue(graph.vertexInGraph[1].edges[0].number == 0);
			Assert::IsTrue(graph.vertexInGraph[1].edges[0].weight == 10);

			Assert::IsTrue(graph.vertexInGraph[5].edges[0].number == 2);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].weight == 1);
			Assert::IsTrue(graph.vertexInGraph[2].edges[0].number == 5);
			Assert::IsTrue(graph.vertexInGraph[2].edges[0].weight == 1);


			Assert::IsTrue(graph.vertexInGraph[0].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges.size() == 1);
			Assert::IsTrue(graph.vertexInGraph[3].edges.empty());
		}
	};
}