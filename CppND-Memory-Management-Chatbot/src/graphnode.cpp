#include "graphedge.h"
#include "graphnode.h"

#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{    
   //std::cout << "Before Move Assignment" << std::endl; 
  	_chatBot = std::move(chatbot);
    //std::cout << "Before SetCurrentNode" << std::endl;
    //_chatBot.botPrint();
    _chatBot.SetCurrentNode(this);
  	std::cout << "After SetCurrentNode" << std::endl;
}


void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    return _childEdges[index].get();
    ////
    //// EOF STUDENT CODE
}