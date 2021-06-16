#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // KJ - We don't need to delete chatbot since its not managed by graph node

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) // KJ - keep this the same
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // KJ - change this to a unique pointer
{
    _childEdges.push_back(std::move(edge));  // KJ - move the edge ownership
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) 
{
    _chatBot = chatbot; // KJ - use the move constructor that was overloaded
     _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));  // KJ - move chatbot when called
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get(); // KJ - return the pointer address

    ////
    //// EOF STUDENT CODE
}