#include "ASpell.hpp"

const std::string &ASpell::getName() const
{
	return (name);
}

const std::string &ASpell::getEffects() const
{
	return (effects);
}

void ASpell::setEffects(const std::string &effects)
{
	this->effects = effects;
}

ASpell::ASpell *clone()
{
	return (this);
}

ASpell::ASpell(const std::string name, const std::string effects) : name(name), effects(effects)
{

}

ASpell::~ASpell()
{

}


