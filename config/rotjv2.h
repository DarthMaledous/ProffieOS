#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1300
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
   { "Ksith_LS6_SS", "tracks/rotj.wav",
   StylePtr<InOutHelper<SimpleClash<Lockup<Blast<AudioFlicker<Rgb<10,255,12>,White>,SteelBlue>,AudioFlicker<AudioFlicker<Yellow,Black>,White>>,Blue,40>,180,800,Black>>(),"ROTJv2"},
   { "FF_Betrayal", "tracks/traya.wav",
   StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Gradient<Cyan,LightCyan>,SteelBlue>,AudioFlicker<Gradient<GreenYellow,Yellow>,White>>,Gradient<DeepSkyBlue,Yellow>,40>,300,800,Black>>(),"cybluez"},
   { "noss/Ilum", "tracks/rotj.wav",
   StylePtr<InOutHelper<SimpleClash<Lockup<Blast<AudioFlicker<DeepSkyBlue,SteelBlue>,White>,AudioFlicker<AudioFlicker<Yellow,White>,White>>,Blue,40>,300,800,Black>>(),"steelBlue"},
   { "Ksith_LS6_SS", "tracks/mars.wav",
   StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Pulsing<SpringGreen,GreenYellow,2500>,White>,AudioFlicker<HumpFlicker<LightYellow,LightCyan,50>,Red>>,HoneyDew,40>,180,800,Black>>(),"ROTJv2Pulse"},
// Transformer Blades //
//Red
	{ "noss/Glare", "tracks/kylo2.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<Orange,0,1,Red,100,800,4600>,White>,BrownNoiseFlicker<OrangeRed,Yellow,100>>,White,40>,300,800,Black>>(),"XfmrRed"},
//Green
	{ "noss/DaddyIssues", "tracks/mars.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<Orange,0,1,Green,100,800,4600>,SteelBlue>,BrownNoiseFlicker<Yellow,OrangeRed,500>>,LightCyan,40>,300,800,Black>>(),"XfmrBlue"},
//Cyan
	{ "noss/EpisodeVI", "tracks/rotj.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<Aquamarine,0,1,Cyan,100,800,4600>,SteelBlue>,BrownNoiseFlicker<SteelBlue,GhostWhite,250>>,Yellow,40>,300,800,Black>>(),"XfmrCyan"},
//Blue
	{ "noss/TERRAFORM", "tracks/mars.wav",
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<SteelBlue,0,1,DeepSkyBlue,100,800,4600>,Magenta>,BrownNoiseFlicker<Blue,GhostWhite,250>>,Yellow,40>,300,800,Black>>(),"XfmrBlue"},
// End of Transformer Blades //
	
// Kylo type bladestyles //
//OrangeRed_Yellow
	{ "noss/Desolation2", "tracks/kylo1.wav", 
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<BrownNoiseFlicker<OrangeRed,Yellow,100>,SpringGreen>,AudioFlicker<GreenYellow,White>>,Magenta,40>,185,800,Black>>(),"KyloRed"},
//Jedi_Green
	{ "FF_Betrayal", "tracks/traya.wav",
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<BrownNoiseFlicker<Green,LightYellow,350>,Red>,HumpFlicker<Green,Magenta,75>>,Cyan,80>,185,800,Black>>(),"KyloJedi"},
// End of Kylo bladestyles //

// Pusling blade styles //
//Sith Pulse
	{ "SmthFuzz", "tracks/sith1.wav", 
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Pulsing<OrangeRed,Orange,3500>,White>,HumpFlicker<Green,Red,50>>,Rgb<195,100,255>,65>,195,800,Black>>(),"SithPulse"},
//Jedi Pulse
	{ "SmthJedi", "tracks/uranus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Pulsing<SpringGreen,GreenYellow,3500>,Orange>,HumpFlicker<Cyan,Ivory,50>>,Rgb<195,100,255>,65>,195,800,Black>>(),"JediPulse"},
//Mace Pulse
	{ "TthCrstl", "tracks/venus.wav",
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Pulsing<Rgb<150,0,255>,Rgb<50,0,230>,3500>,DarkOrange>,HumpFlicker<Rgb<185,95,0>,Rgb<255,100,150>,55>>,Rgb<195,100,255>,65>,195,800,Black>>(),"MacePulse"},
// End of Pulsing blade styles //
	
// Begin default Proffie bladestyles //
   { "TeensySF", "tracks/venus.wav",
    StyleNormalPtr<CYAN, WHITE, 300, 800>(), "cyan"},
   { "SmthJedi", "tracks/mars.wav",
    StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(), "blue"},
   { "SmthGrey", "tracks/mercury.wav",
    StyleFirePtr<RED, YELLOW>(), "fire"},
   { "SmthFuzz", "tracks/uranus.wav",
    StyleNormalPtr<RED, WHITE, 300, 800>(), "red"},
   { "RgueCmdr", "tracks/venus.wav",
    StyleFirePtr<BLUE, CYAN>(), "blue fire"},
   { "TthCrstl", "tracks/mars.wav",
    StylePtr<InOutHelper<EASYBLADE(OnSpark<GREEN>, WHITE), 300, 800> >(), "green"},
   { "TeensySF", "tracks/mercury.wav",
    StyleNormalPtr<WHITE, RED, 300, 800, RED>(), "white"},
   { "SmthJedi", "tracks/uranus.wav",
    StyleNormalPtr<AudioFlicker<YELLOW, WHITE>, BLUE, 300, 800>(), "yellow"},
   { "SmthGrey", "tracks/venus.wav",
    StylePtr<InOutSparkTip<EASYBLADE(MAGENTA, WHITE), 300, 800> >(), "magenta"},
   { "SmthFuzz", "tracks/mars.wav",
    StyleNormalPtr<Gradient<RED, BLUE>, Gradient<CYAN, YELLOW>, 300, 800>(), "gradient"},
   { "RgueCmdr", "tracks/mercury.wav",
    StyleRainbowPtr<300, 800>(), "rainbow"},
   { "TthCrstl", "tracks/uranus.wav",
    StyleStrobePtr<WHITE, Rainbow, 15, 300, 800>(), "strobe"},
   { "TeensySF", "tracks/venus.wav",
    &style_pov, "POV"},
   { "SmthJedi", "tracks/mars.wav",
    &style_charging, "Battery\nLevel"}
};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<144, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif