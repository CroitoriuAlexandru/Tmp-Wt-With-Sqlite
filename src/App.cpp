#include "include/App.h"

#include "include/PageOne.h"
#include "include/PageTwo.h"

#include <Wt/WApplication.h>

App::App()
	: WContainerWidget()
{
	addStyleClass("application");

	session_ = std::make_shared<Session>();

	createNavigation();
}

void App::createNavigation()
{
	navigation_ = addWidget(std::make_unique<Wt::WNavigationBar>());
	navigation_->setObjectName("navigation");

	// navigation->setResponsive(true);
	navigation_->addStyleClass("navbar navbar-dark bg-dark navbar-expand-sm");
	navigation_->setTitle("Navigation", Wt::WLink(Wt::LinkType::InternalPath, "/PageOne"));

	contentsStack_ = addWidget(std::make_unique<Wt::WStackedWidget>());
	contentsStack_->setTransitionAnimation(Wt::WAnimation(Wt::AnimationEffect::SlideInFromRight, Wt::TimingFunction::EaseInOut), true);
	contentsStack_->addStyleClass("contents");

	auto mainMenu_ = navigation_->addMenu(std::make_unique<Wt::WMenu>(contentsStack_));
	mainMenu_->setInternalPathEnabled();

	// create pages content
	auto pageOne = std::make_unique<PageOne>(session_);
	auto pageTwo = std::make_unique<PageTwo>();

	// create menu items 
	auto menuItemOne = std::make_unique<Wt::WMenuItem>("one");
	auto menuItemTwo = std::make_unique<Wt::WMenuItem>("two");

	// add pages to stack
	mainMenu_->addItem("one", std::move(pageOne))->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/PageOne"));
	mainMenu_->addItem("two", std::move(pageTwo))->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/PageTwo"));

	// default starting page
	Wt::WApplication::instance()->setInternalPath("/PageOne`", true);
}
