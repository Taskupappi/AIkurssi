#include "SearchLevel.h"

SearchLevel::SearchLevel(yam2d::Texture *input)
	:inputTexture(input)
{

}

float SearchLevel::getG(SearchNode *fromNode, const Position &toPos)
{
	float dx = (float)(toPos.first - fromNode->pos.first);
	float dy = (float)(toPos.second - fromNode->pos.second);
	float result = sqrtf(dx * dx + dy * dy);
	return result;
}

float SearchLevel::getH(const Position &fromPos, const Position &toPos)
{
	float dx = (float)(toPos.first - fromPos.first);
	float dy = (float)(toPos.second - fromPos.second);
	float result = sqrtf(dx * dx + dy * dy);
	return result;
}

bool SearchLevel::isWalkable(int posX, int posY)
{

	if (posX < 0 || posY < 0 || posX >= inputTexture->getWidth() || posY >= inputTexture->getHeight())
	{
		return false;
	}
	unsigned char *pixel = inputTexture->getPixel(posX, posY);
	bool isNotWalkable = path::isGreen(pixel);
	return !isNotWalkable;
}

std::vector<Position> SearchLevel::GetAdjacentNodes(int posX, int posY)
{
	std::vector<Position> result;
	//add adjacent nodes to result
	if (isWalkable(posX + 1, posY));
	result.push_back(Position(posX + 1, posY));

	if (isWalkable(posX - 1, posY));
	result.push_back(Position(posX - 1, posY));

	if (isWalkable(posX, posY + 1));
	result.push_back(Position(posX, posY + 1));

	if (isWalkable(posX, posY - 1));
	result.push_back(Position(posX, posY - 1));

	return result;

}