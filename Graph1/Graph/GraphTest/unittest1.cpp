#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph/vertex.h"
#include "../Graph/edge.h"
#include "../Graph/graph.h"
#include "../Graph/Nag³ówek.h"
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
			graph.connectOriented("vertex0", "vertex1");
			graph.connectOriented("vertex5", "vertex2");

			Assert::IsTrue(graph.vertexInGraph[0].edges[0].number == 1);
			Assert::IsTrue(graph.vertexInGraph[5].edges[0].number == 2);
			Assert::IsTrue(graph.vertexInGraph[1].edges.size() == 0);
			Assert::IsTrue(graph.vertexInGraph[2].edges.size()==0);

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

		TEST_METHOD(removeEdgeGraph)
		{
			graph graph;
			graph.addVertex("0");
			graph.addVertex("1");
			graph.addVertex("2");
			graph.addVertex("3");
			graph.addVertex("4");
			graph.addVertex("5");

			graph.connectUnoriented("0", "1");
			graph.connectUnoriented("2", "5");

			graph.removeEdge("0", "1");
			graph.removeEdge("2", "5");

			graph.removeEdge("1", "0");
			graph.removeEdge("5", "2");
			Assert::IsTrue(graph.vertexInGraph[0].edges.size()==0);
			Assert::IsTrue(graph.vertexInGraph[1].edges.size() == 0);
			Assert::IsTrue(graph.vertexInGraph[2].edges.size() == 0);
			Assert::IsTrue(graph.vertexInGraph[3].edges.size() == 0);
			Assert::IsTrue(graph.vertexInGraph[4].edges.size() == 0);
		
		}

		TEST_METHOD(saveAsMatrix)
		{
			graph graph;
			graph.addVertex("0");
			graph.addVertex("1");
			graph.addVertex("2");
			graph.addVertex("3");
			graph.addVertex("4");
			

			graph.connectUnoriented("0", "1");
			graph.connectUnoriented("2", "1");
			graph.connectUnoriented("3", "4");

			graph.saveAsMarix();

			graph.matrix;
			const std::vector<std::vector<bool>> test{
			{0,1,0,0,0},
			{1,0,1,0,0},
			{0,1,0,0,0},
			{0,0,0,0,1},
			{0,0,0,1,0}
				};
			for(int i=0; i<graph.matrix.size(); i++)
			{
				for(int j=0; j<graph.matrix[i].size(); j++)
				{
					Assert::IsTrue(graph.matrix[i][j] == test[i][j]);
				}
			}
			
		}

		TEST_METHOD(graphOrder)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");
			Assert::IsTrue(g.graphOrder() == 5);
		}

		TEST_METHOD(graphSize)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");

			g.connectUnoriented("0", "1");
			g.connectUnoriented("1", "2");
			g.connectUnoriented("2", "3");
			g.connectUnoriented("4", "1");
			g.connectUnoriented("3", "1");
			g.connectUnoriented("3", "4");

			Assert::IsTrue(g.graphSize() == 6);
		}

		TEST_METHOD(vertexDegree)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");

			g.connectUnoriented("0", "1");
			g.connectUnoriented("0", "2");
			g.connectUnoriented("0", "3");
			Assert::IsTrue(g.vertexDegree("0") == 3);

			g.connectUnoriented("4", "1");
			g.connectUnoriented("4", "1");
			Assert::IsTrue(g.vertexDegree("4") == 2);
		}

		TEST_METHOD(graphComplete)
		{
			graph graph1;
			graph1.addVertex("0");
			Assert::IsTrue(graph1.isComplete() == true);

			graph graph2;
			graph2.addVertex("0");
			graph2.addVertex("1");
			graph2.connectUnoriented("0", "1");
			Assert::IsTrue(graph2.isComplete() == true);

			graph graph3;
			graph3.addVertex("0");
			graph3.addVertex("1");
			graph3.addVertex("2");
			graph3.connectUnoriented("0", "1");
			graph3.connectUnoriented("2", "1");
			Assert::IsTrue(graph3.isComplete() == false);
		}

		TEST_METHOD(graphDegree)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");

			g.connectUnoriented("0", "1");
			g.connectUnoriented("0", "2");
			g.connectUnoriented("0", "3");
		

			g.connectUnoriented("4", "1");
			g.connectUnoriented("4", "1");
			
			Assert::IsTrue(g.graphDegree() == 3);
		}

		TEST_METHOD(areConnected)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");

			g.connectUnoriented("0", "1");
			g.connectUnoriented("0", "2");
			g.connectUnoriented("0", "3");


			g.connectUnoriented("4", "1");
			Assert::IsTrue(g.areVertexConnected(0, 1) == true);
			Assert::IsTrue(g.areVertexConnected(0, 2) == true);
			Assert::IsTrue(g.areVertexConnected(0, 3) == true);
			Assert::IsTrue(g.areVertexConnected(4, 1) == true);

			Assert::IsTrue(g.areVertexConnected(2, 3) == false);
			Assert::IsTrue(g.areVertexConnected(2, 4) == false);
			Assert::IsTrue(g.areVertexConnected(0, 4) == false);
		}

		TEST_METHOD(makeUnoriented)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");

			g.connectOriented("0", "1");
			g.connectOriented("0", "2");
			g.connectOriented("0", "3");
			
			g.connectOriented("1", "0");
			g.connectOriented("1", "2");
			g.connectOriented("1", "3");

			g.connectOriented("2", "0");
			g.connectOriented("2", "1");
			g.connectOriented("2", "3");

			g.connectOriented("3", "0");
			g.connectOriented("3", "1");
			g.connectOriented("3", "2");

			g.makeUnoriented();
			g.saveAsMarix();

			const std::vector<std::vector<bool>> test{
			{0,1,1,1},
			{1,0,1,1},
			{1,1,0,1},
			{1,1,1,0}
			};

			for(int i=0; i<test.size(); i++)
			{
				for(int j=0; j<test.size(); j++)
				{
					Assert::IsTrue(test[i][j] == g.matrix[i][j]);
				}
			}
		}

		TEST_METHOD(resetVisited)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");

			g.vertexInGraph[0].visited = true;
			g.vertexInGraph[1].visited = true;
			g.vertexInGraph[2].visited = true;
			g.vertexInGraph[3].visited = true;

			g.resetVisited();

			for(int i=0; i<g.vertexInGraph.size(); i++)
			{
				Assert::IsTrue(g.vertexInGraph[i].visited==false);
			}

			g.vertexInGraph[1].visited = true;
			Assert::IsTrue(g.vertexInGraph[0].visited == false);
			Assert::IsTrue(g.vertexInGraph[1].visited == true);
			Assert::IsTrue(g.vertexInGraph[2].visited == false);
			Assert::IsTrue(g.vertexInGraph[3].visited == false);
		}

		TEST_METHOD(firstUnivisited)
		{
			graph g;
			g.addVertex("0");
			g.addVertex("1");
			g.addVertex("2");
			g.addVertex("3");
			g.addVertex("4");
			g.addVertex("5");
			g.addVertex("6");

			Assert::IsTrue(g.firstUnvisited() == 0);
			g.vertexInGraph[0].visited = true;
			g.vertexInGraph[1].visited = true;
			Assert::IsTrue(g.firstUnvisited() == 2);
			g.vertexInGraph[2].visited = true;
			g.vertexInGraph[3].visited = true;
			g.vertexInGraph[4].visited = true;
			Assert::IsTrue(g.firstUnvisited() == 5);
			g.vertexInGraph[2].visited = true;
			Assert::IsTrue(g.firstUnvisited() == 6);
		}
	};
}