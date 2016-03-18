(function e(b,g,d){function c(k,i){if(!g[k]){if(!b[k]){var h=typeof require=="function"&&require;
if(!i&&h){return h(k,!0)}if(a){return a(k,!0)}throw new Error("Cannot find module '"+k+"'")
}var j=g[k]={exports:{}};b[k][0].call(j.exports,function(l){var m=b[k][1][l];return c(m?m:l)
},j,j.exports,e,b,g,d)}return g[k].exports}var a=typeof require=="function"&&require;
for(var f=0;f<d.length;f++){c(d[f])}return c})({1:[function(c,f,b){var d={cssPropertyAvailable:c("./ac-feature/cssPropertyAvailable"),localStorageAvailable:c("./ac-feature/localStorageAvailable")};
var a=Object.prototype.hasOwnProperty;d.threeDTransformsAvailable=function(){if(typeof this._threeDTransformsAvailable!=="undefined"){return this._threeDTransformsAvailable
}var i,g;try{this._threeDTransformsAvailable=false;if(a.call(window,"styleMedia")){this._threeDTransformsAvailable=window.styleMedia.matchMedium("(-webkit-transform-3d)")
}else{if(a.call(window,"media")){this._threeDTransformsAvailable=window.media.matchMedium("(-webkit-transform-3d)")
}}if(!this._threeDTransformsAvailable){if(!(g=document.getElementById("supportsThreeDStyle"))){g=document.createElement("style");
g.id="supportsThreeDStyle";g.textContent="@media (transform-3d),(-o-transform-3d),(-moz-transform-3d),(-ms-transform-3d),(-webkit-transform-3d) { #supportsThreeD { height:3px } }";
document.querySelector("head").appendChild(g)}if(!(i=document.querySelector("#supportsThreeD"))){i=document.createElement("div");
i.id="supportsThreeD";document.body.appendChild(i)}this._threeDTransformsAvailable=(i.offsetHeight===3)||g.style.MozTransform!==undefined||g.style.WebkitTransform!==undefined
}return this._threeDTransformsAvailable}catch(h){return false}};d.canvasAvailable=function(){if(typeof this._canvasAvailable!=="undefined"){return this._canvasAvailable
}var g=document.createElement("canvas");this._canvasAvailable=!!(typeof g.getContext==="function"&&g.getContext("2d"));
return this._canvasAvailable};d.sessionStorageAvailable=function(){if(typeof this._sessionStorageAvailable!=="undefined"){return this._sessionStorageAvailable
}try{if(typeof window.sessionStorage!=="undefined"&&typeof window.sessionStorage.setItem==="function"){window.sessionStorage.setItem("ac_browser_detect","test");
this._sessionStorageAvailable=true;window.sessionStorage.removeItem("ac_browser_detect","test")
}else{this._sessionStorageAvailable=false}}catch(g){this._sessionStorageAvailable=false
}return this._sessionStorageAvailable};d.cookiesAvailable=function(){if(typeof this._cookiesAvailable!=="undefined"){return this._cookiesAvailable
}this._cookiesAvailable=(a.call(document,"cookie")&&!!navigator.cookieEnabled)?true:false;
return this._cookiesAvailable};d.__normalizedScreenWidth=function(){if(typeof window.orientation==="undefined"){return window.screen.width
}return window.screen.width<window.screen.height?window.screen.width:window.screen.height
};d.touchAvailable=function(){return !!(("ontouchstart" in window)||window.DocumentTouch&&document instanceof window.DocumentTouch)
};d.isDesktop=function(){if(!this.touchAvailable()&&!window.orientation){return true
}return false};d.isHandheld=function(){return !this.isDesktop()&&!this.isTablet()
};d.isTablet=function(){return !this.isDesktop()&&this.__normalizedScreenWidth()>480
};d.isRetina=function(){var g=["min-device-pixel-ratio:1.5","-webkit-min-device-pixel-ratio:1.5","min-resolution:1.5dppx","min-resolution:144dpi","min--moz-device-pixel-ratio:1.5"];
var h;if(window.devicePixelRatio!==undefined){if(window.devicePixelRatio>=1.5){return true
}}else{for(h=0;h<g.length;h+=1){if(window.matchMedia("("+g[h]+")").matches===true){return true
}}}return false};d.svgAvailable=function(){return document.implementation.hasFeature("http://www.w3.org/TR/SVG11/feature#Image","1.1")
};f.exports=d},{"./ac-feature/cssPropertyAvailable":2,"./ac-feature/localStorageAvailable":3}],2:[function(c,f,b){var g=null;
var h=null;var a=null;var d=null;f.exports=function(s){if(g===null){g=document.createElement("browserdetect").style
}if(h===null){h=["-webkit-","-moz-","-o-","-ms-","-khtml-",""]}if(a===null){a=["Webkit","Moz","O","ms","Khtml",""]
}if(d===null){d={}}s=s.replace(/([A-Z]+)([A-Z][a-z])/g,"$1\\-$2").replace(/([a-z\d])([A-Z])/g,"$1\\-$2").replace(/^(\-*webkit|\-*moz|\-*o|\-*ms|\-*khtml)\-/,"").toLowerCase();
switch(s){case"gradient":if(d.gradient!==undefined){return d.gradient}s="background-image:";
var q="gradient(linear,left top,right bottom,from(#9f9),to(white));";var p="linear-gradient(left top,#9f9, white);";
g.cssText=(s+h.join(q+s)+h.join(p+s)).slice(0,-s.length);d.gradient=(g.backgroundImage.indexOf("gradient")!==-1);
return d.gradient;case"inset-box-shadow":if(d["inset-box-shadow"]!==undefined){return d["inset-box-shadow"]
}s="box-shadow:";var r="#fff 0 1px 1px inset;";g.cssText=h.join(s+r);d["inset-box-shadow"]=(g.cssText.indexOf("inset")!==-1);
return d["inset-box-shadow"];default:var o=s.split("-");var k=o.length;var n;var m;
var l;if(o.length>0){s=o[0];for(m=1;m<k;m+=1){s+=o[m].substr(0,1).toUpperCase()+o[m].substr(1)
}}n=s.substr(0,1).toUpperCase()+s.substr(1);if(d[s]!==undefined){return d[s]}for(l=a.length-1;
l>=0;l-=1){if(g[a[l]+s]!==undefined||g[a[l]+n]!==undefined){d[s]=true;return true
}}return false}}},{}],3:[function(d,f,b){var a=null;f.exports=function c(){if(a===null){a=!!(window.localStorage&&window.localStorage.non_existent!==null)
}return a}},{}],4:[function(b,c,a){a.Clock=b("./ac-animation-sequencer/Clock");
a.PlayerMonitor=b("./ac-animation-sequencer/PlayerMonitor");a.Timeline=b("./ac-animation-sequencer/Timeline");
a.Tween=b("./ac-animation-sequencer/Tween");a.BasicPlayer=b("./ac-animation-sequencer/player/BasicPlayer");
a.MediaPlayer=b("./ac-animation-sequencer/player/MediaPlayer");a.Pause=b("./ac-animation-sequencer/controllers/Pause");
a.MediaGroup=b("./ac-animation-sequencer/controllers/MediaGroup");a.BaseClip=b("./ac-animation-sequencer/clip/BaseClip");
a.CompositeClip=b("./ac-animation-sequencer/clip/CompositeClip");a.TimedClip=b("./ac-animation-sequencer/clip/TimedClip");
a.TweenClip=b("./ac-animation-sequencer/clip/TweenClip");a.ElementClip=b("./ac-animation-sequencer/clip/ElementClip");
a.VideoClip=b("./ac-animation-sequencer/clip/VideoClip");a.ReversibleVideo=b("./ac-animation-sequencer/adapters/ReversibleVideo")
},{"./ac-animation-sequencer/Clock":5,"./ac-animation-sequencer/PlayerMonitor":6,"./ac-animation-sequencer/Timeline":7,"./ac-animation-sequencer/Tween":8,"./ac-animation-sequencer/adapters/ReversibleVideo":11,"./ac-animation-sequencer/clip/BaseClip":12,"./ac-animation-sequencer/clip/CompositeClip":13,"./ac-animation-sequencer/clip/ElementClip":14,"./ac-animation-sequencer/clip/TimedClip":15,"./ac-animation-sequencer/clip/TweenClip":16,"./ac-animation-sequencer/clip/VideoClip":17,"./ac-animation-sequencer/controllers/MediaGroup":18,"./ac-animation-sequencer/controllers/Pause":19,"./ac-animation-sequencer/player/BasicPlayer":20,"./ac-animation-sequencer/player/MediaPlayer":21}],5:[function(b,c,a){function f(){this._currentTimeMS=0;
this._playbackRate=1;this._paused=true;this._resetStartTime()}var d=f.prototype;
d._updateCurrentTime=function(){var h,g=Date.now();if(this._paused){h=0}else{h=(g-this._startTime)
}this._currentTimeMS+=(h*this._playbackRate);this._startTime=g};d._resetStartTime=function(){this._startTime=Date.now()
};d.play=function(){this._resetStartTime();this._paused=false;return this};d.pause=function(){this._updateCurrentTime();
this._paused=true;return this};d.isPaused=function(){return this._paused};d.getCurrentTime=function(){this._updateCurrentTime();
return this._currentTimeMS/1000};d.setCurrentTime=function(g){if(isNaN(g)){return
}this._resetStartTime();this._currentTimeMS=g*1000};d.getPlaybackRate=function(){return this._playbackRate
};d.setPlaybackRate=function(g){if(isNaN(g)){return}this._playbackRate=g};c.exports=f
},{}],6:[function(c,f,a){var h=c("ac-event-emitter").EventEmitter;var b=c("./vendor/utils");
function d(j,k,i){i=(Array.isArray(k)?i:k)||{};k=(Array.isArray(k)?k:[]);this._player=j;
this._isMonitoring=true;this._times=[0];this._previous=0;this._currentTimeIndex=0;
this._options=b.defaults({active:true,readyEvent:"canplaythrough",autoInit:false},i);
if(this._options.autoInit){this.addPlayerListener(this._options.readyEvent,this._init.bind(this,k))
}}var g=d.prototype=new h();g.addPlayerListener=function(j,i){if(typeof this._player.addEventListener==="function"){this._player.addEventListener(j,i)
}else{if(typeof this._player.on==="function"){this._player.on(j,i)}}};g._init=function(i){if(this._initialized){return
}this.addTime(this._player.duration);if(i&&i.length){i.forEach(this.addTime.bind(this))
}this._resetNextTimes();this._attachEvents();if(this._options.active){this._listen()
}this.trigger("ready");this._initialized=true};g._attachEvents=function(){this.addPlayerListener("play",this._handlePlay.bind(this));
if(!this._options.active){this.addPlayerListener("timeupdate",this._listen.bind(this))
}this.addPlayerListener("seeking",this._handleSeek.bind(this));this.addPlayerListener("ratechange",this._handleRateChange.bind(this))
};g.addTime=function(i,j){i=parseFloat(i);if(isNaN(i)){throw new TypeError('Invalid time "'+i+'", expected Number"')
}if(this._times.indexOf(i)===-1){this._times.push(i);this._times.sort(function(l,k){return l-k
})}if(typeof j==="function"){this.on("time:"+i,j)}this._resetNextTimes()};g._handleSeek=function(){var j=this._player.currentTime;
var i=this._times.indexOf(j);this._currentTimeIndex=(i!==-1)?i:this._calcCurrentTimeIndex(j);
this._resetNextTimes()};g._handlePlay=function(){this._resetNextTimes();this._listen()
};g._handleRateChange=function(){var j=this._player.currentTime;var k=j===this._player.duration;
var i=this._times.indexOf(j)!==-1;this._currentTimeIndex=(k||i)?this._currentTimeIndex:this._calcCurrentTimeIndex(j);
this._resetNextTimes()};g._resetNextTimes=function(){var i=this._calcNextTimeIndex(this._currentTimeIndex);
if(b.isNum(i)){this._nextTimeIndex=i;this._nextTimePoint=this._times[i]}};g._calcCurrentTimeIndex=function(m){var j,l,k,i;
k=this._calcTimeIndices(m);l=k[0];j=k[1];i=(this._forwards())?l:j;return(this._validTimeIndex(i))?i:null
};g._validTimeIndex=function(i){return(0<=i&&i<=this._times.length-1)};g._calcNextTimeIndex=function(i){var j=i+((this._forwards())?1:-1);
return(this._validTimeIndex(j))?j:null};g._calcTimeIndices=function(j){var i=this._times.reduce(function(l,m,k){return(j>=this._times[l+1])?k:l
}.bind(this),0);return[i,i+1]};g._reachedNextTime=function(m){var l=this._forwards();
var j=this._nextTimePoint;var k=!this._player.paused||m===0||m===this._player.duration;
var n=l&&m>=j;var i=!l&&m<=j;return k&&(n||i)};g._forwards=function(){return this._player.playbackRate>0
};g._listen=function(){var j=this._player.currentTime;var i=this._previous;var k=this._reachedNextTime(j);
if(k){this._enterTimePoint(i)}this._previous=j;if(this._options.active&&!this._player.paused){window.requestAnimationFrame(this._listen.bind(this))
}};g._enterTimePoint=function(j){var i=this._calcNextTimeIndex(this._currentTimeIndex);
if(!b.isNum(i)){return}var k=this._times[i];this.trigger("time:"+k,{previous:j,next:this._player.currentTime,requested:k});
this._currentTimeIndex=i;this._resetNextTimes()};f.exports=d},{"./vendor/utils":24}],7:[function(b,c,a){var i=b("./clip/CompositeClip");
var h=b("./clip/TimedClip");var g="Invalid duration for the following clip; must be number greater than or equal to zero (0)";
var f='Invalid clip type: "';var d={clipTypes:{Tween:b("./clip/TweenClip"),Element:b("./clip/ElementClip")},create:function(j){if(this.validTimeline(j)){return this._buildTimeline(j)
}if(this.debug&&console&&typeof console.warn==="function"){console.warn("Timeline: invalid timeline data:",j)
}return null},validTimeline:function(j){return Array.isArray(j)&&j.every(this._validClip.bind(this))
},_getClipType:function(j){if(typeof j==="string"&&this.clipTypes[j]){j=this.clipTypes[j]
}if(this._isValidClipType(j)){return j}return false},_isValidClipType:function(j){return(j&&j.create)
},_validate:function(){return true},_buildTimeline:function(k){var j=k.map(this._createTimedClip.bind(this));
return new i(j)},_createTimedClip:function(k){var j=this._getClipType(k.clip);return new h(j.create(k),k)
},_validClip:function(m){var l;var j=this._getClipType(m.clip);var k=this._validDuration(m);
if(!j){throw new TypeError(f+m.clip+'"\n\n'+JSON.stringify(m))}l=j.validate||this._validate;
return k&&l(m)},_validDuration:function(k){var l=k.duration;var j=typeof l==="number"&&l>0;
if(!j){throw new TypeError(g+"\n\n"+JSON.stringify(k))}return j}};c.exports=d},{"./clip/CompositeClip":13,"./clip/ElementClip":14,"./clip/TimedClip":15,"./clip/TweenClip":16}],8:[function(b,a,d){var i=b("./vendor/KeySpline");
var g=b("./vendor/EasingFunctions");var k="Easing option must be one of: String, Array[Number:4], or Function. Given: ";
var c="KeySpline easing expected an array of exactly four (4) numbers, given: ";
var j=b("./vendor/utils");function h(l){l=l||{};j.defaultProps(this,h.defaults,l);
this._easingFunction=this._createEasing(this.easing)}h.defaults={from:0,to:1,duration:1,easing:"linear"};
var f=h.prototype;f._createEasing=function(l){var m;if(typeof l==="string"){m=this._createPredefinedEasing(l)
}else{if(Array.isArray(l)){m=this._createBezierEasing(l)}else{if(typeof l==="function"){m=l
}else{throw new TypeError(k+l)}}}return m};f._createBezierEasing=function(l){var n;
var o=l;var m=l.every(function(p){return(typeof p==="number")});if(l.length!==4||!m){throw new TypeError(c+l)
}n=new i(o[0],o[1],o[2],o[3]);return function(p,s,r,q){return s+n.get(p/q)*r}};
f._createPredefinedEasing=function(n){var m=g[n];var l="";if(!m){l+='Easing function "'+m;
l+='" not recognized among the following: ';l+=Object.keys(g).join(", ");throw new Error(l)
}return m};f._getInterpolatedValue=function(l,o,n,m){return this._easingFunction(l,o,n,m)
};f.valueAtLocation=function(m){if(m<0||m>1){return null}var l=this.duration*m;
return this.valueAtTime(l)};f.valueAtPercent=function(l){if(l<0||l>100){return null
}return this.valueAtLocation(l/100)};f.valueAtTime=function(l){if(l<0||l>this.duration){return null
}return this._getInterpolatedValue(l,this.from,this.to-this.from,this.duration)
};a.exports=h},{"./vendor/EasingFunctions":22,"./vendor/KeySpline":23,"./vendor/utils":24}],9:[function(c,d,b){function a(g){this._media=g
}var f=a.prototype;f.on=function(){this._media.addEventListener.apply(this._media,arguments)
};f.off=function(){this._media.removeEventListener.apply(this._media,arguments)
};f.getCurrentTime=function(){return this._media.currentTime};f.setCurrentTime=function(g){this._media.currentTime=g
};f.getDuration=function(){return this._media.duration};f.getPlaybackRate=function(){return this._media.playbackRate
};f.setPlaybackRate=function(g){this._media.playbackRate=g};d.exports=a},{}],10:[function(c,d,a){if(typeof Object.defineProperties!=="function"){return
}var g=c("ac-event-emitter").EventEmitter;function b(h){this._player=h}var f=b.prototype=new g();
f.addEventListener=function(){this._player.on.apply(this._player,arguments)};f.removeEventListener=function(){this._player.on.apply(this._player,arguments)
};f.play=function(){this._player.play.apply(this._player,arguments)};f.pause=function(){this._player.pause.apply(this._player,arguments)
};Object.defineProperties(b.prototype,{paused:{get:function(){return this._player.isPaused()
},set:function(h){this._player.setPaused(h)}},currentTime:{get:function(){return this._player.getCurrentTime()
},set:function(h){this._player.setCurrentTime(h)}},duration:{get:function(){return this._player.getDuration()
}},playbackRate:{get:function(){return this._player.getPlaybackRate()},set:function(h){this.trigger("ratechange",{rate:h});
this._player.setPlaybackRate(h)}}});d.exports=b},{}],11:[function(b,c,a){if(typeof Object.defineProperties!=="function"){return
}var f=b("ac-event-emitter").EventEmitter;function g(h){this._media=h;this._lastTime=null;
g.passThroughEvents.forEach(this.passThroughEvent.bind(this));g.interceptedEvents.forEach(this.interceptEvent.bind(this))
}g.interceptedEvents=["seeking","play"];g.passThroughEvents=["abort","canplay","canplaythrough","durationchange","emptied","ended","error","loadeddata","loadedmetadata","loadstart","mozaudioavailable","pause","playing","progress","ratechange","seeked","suspend","timeupdate","volumechange","waiting"];
var d=g.prototype=new f();d.addEventListener=function(h){var i=g.passThroughEvents;
if(i.indexOf(h)>-1){this._media.addEventListener.apply(this._media,arguments)}else{this.on.apply(this,arguments)
}};d.removeEventListener=function(h){var i=g.passThroughEvents;if(i.indexOf(h)>-1){this._media.removeEventListener.apply(this._media,arguments)
}else{this.off.apply(this,arguments)}};d.passThroughEvent=function(h){this._media.addEventListener(h,this._passThrough.bind(this))
};d.interceptEvent=function(h){var i=this["_on"+h];if(typeof i!=="undefined"){this._media.addEventListener(h,i.bind(this))
}};d._passThrough=function(h){this.trigger(h.type,h)};d._onseeking=function(){if(!this._playing){this.trigger("seeking")
}};d._onplay=function(){this.trigger("play")};d.play=function(){if(this.playbackRate<0){this._playing=true;
this._lastTime=null;window.requestAnimationFrame(this._update.bind(this));this.trigger("play")
}else{this._media.play()}};d.load=function(){this._media.load()};d._stop=function(h){h.preventDefault();
h.stopPropagation()};d._update=function(i){var j=i-(this._lastTime||i);var h=this._media.currentTime+((j*this.playbackRate)/1000);
if(h<=0){this._media.currentTime=0;this._playing=false;this.trigger("returned",{type:"returned"})
}else{this._media.currentTime=h;this.trigger("timeupdate",{type:"timeupdate"})}this._lastTime=i;
if(this._playing){window.requestAnimationFrame(this._update.bind(this))}};d.pause=function(){this._playing=false;
this._media.pause()};Object.defineProperties(g.prototype,{currentTime:{get:function(){return this._media.currentTime
},set:function(h){this._media.currentTime=h}},duration:{get:function(){return this._media.duration
}},buffered:{get:function(){return this._media.buffered}},playbackRate:{get:function(){return this._media.playbackRate
},set:function(h){this._media.playbackRate=h}},paused:{get:function(){return !this._playing&&this._media.paused
},set:function(h){this._media.paused=h}}});c.exports=g},{}],12:[function(b,a,d){var h=b("../vendor/KeySpline");
var i=b("ac-style-renderer").LogRenderer;var g=b("../vendor/EasingFunctions");var l="Easing option must be one of: String, Array[Number:4], or Function. Given: ";
var c="KeySpline easing expected an array of exactly four (4) numbers, given: ";
var k=b("ac-event-emitter").EventEmitter;function j(n,m){this.options=m||{};this._renderer=this.options.renderer||i;
this._duration=n;this._currentTime=0;this._easingFunction=this._createEasing(this.options.easing||j.DEFAULT_EASING)
}j.DEFAULT_EASING="linear";var f=j.prototype=new k();f._createEasing=function(m){var n;
if(typeof m==="string"){n=this._createPredefinedEasing(m)}else{if(Array.isArray(m)){n=this._createBezierEasing(m)
}else{if(typeof m==="function"){n=m}else{throw new TypeError(l+m)}}}return n};f._createBezierEasing=function(m){var o;
var p=m;var n=m.every(function(q){return(typeof q==="number")});if(m.length!==4||!n){throw new TypeError(c+m)
}o=new h(p[0],p[1],p[2],p[3]);return function(q,t,s,r){return o.get(q/r)*s}};f._createPredefinedEasing=function(o){var n=g[o];
var m="";if(!n){m+='Easing function "'+n;m+='" not recognized among the following: ';
m+=Object.keys(g).join(", ");throw new Error(m)}return n};f._getInterpolatedValue=function(m,p,o,n){return this._easingFunction(m,p,o,n)
};f.getDuration=function(){return this._duration};f.getCurrentTime=function(){return this._currentTime
};f.setCurrentTime=function(m){this._currentTime=m;this.update()};f.getPlaybackRate=function(){return this._playbackRate
};f.setPlaybackRate=function(m){this._playbackRate=m};f.update=function(){};a.exports=j
},{"../vendor/EasingFunctions":22,"../vendor/KeySpline":23,"ac-style-renderer":94}],13:[function(b,c,a){var g=b("./TimedClip");
function f(h){if(h&&h.length){this._clips=h.map(this._ensureTimedClip);this._duration=this._calcDuration()
}}var d=f.prototype;d._calcDuration=function(h){h=h||this._clips;var i=h.reduce(function(k,l){var j=l.getStartDelay()+l.getDuration();
return(j>k)?j:k},0);return i};d._ensureTimedClip=function(h){if(!(h instanceof g)){h=new g(h)
}return h};d._getLocalTime=function(h,i){return i-h.getStartDelay()};d._getEligibleClips=function(){return this._clips
};d.addClip=function(h){h=this._ensureTimedClip(h);this._clips.push(h);this._duration=this._calcDuration()
};d.on=function(){var h=arguments;this._clips.forEach(function(i){i.on.apply(i,h)
})};d.off=function(){var h=arguments;this._clips.forEach(function(i){i.off.apply(i,h)
})};d.trigger=function(){var h=arguments;this._clips.forEach(function(i){i.trigger.apply(i,h)
})};d.setEasingDirection=function(h){this._clips.forEach(function(i){i.setEasingDirection(h)
})};d.getDuration=function(){return this._duration};d.getCurrentTime=function(){return this._currentTime
};d.setCurrentTime=function(j,i){var h=this._getEligibleClips();if(!h||!h.length){return
}h.forEach(function(k){var l=this._getLocalTime(k,j);k.setCurrentTime(l,i)}.bind(this))
};d.getPlaybackRate=function(){return this._playbackRate};d.setPlaybackRate=function(h){if(isNaN(h)){return
}this._playbackRate=h};c.exports=f},{"./TimedClip":15}],14:[function(c,a,d){var j=c("../vendor/utils");
var h=c("../Tween");var k=c("./BaseClip");var i=c("ac-style-renderer").InlineStyleRenderer;
var b="Invalid element or selector: ";function g(l){l=j.defaults(g.DEFAULTS,l);
this.props=l.props||[];if(l.selector||typeof l.element==="string"){this.el=document.querySelector(l.selector||l.element)
}else{this.el=l.element}if(!this.el||!this.el.nodeType||this.el.nodeType!==1){throw new TypeError(b+l.element)
}if(!l.renderer){this.renderer=i}k.call(this,l.duration,l);this._initProps()}g.DEFAULTS={props:[],selector:null,element:".default_selector",renderer:i,duration:1};
g.create=function(l){return new g(l)};g.validate=function(m){var l="selector" in m||"element" in m;
return l};var f=g.prototype=new k();f._initProps=function(){this.props.forEach(function(l){l.tween=this._createTween({easing:l.easing||k.DEFAULT_EASING,from:l.from,to:l.to,duration:this.getDuration()})
}.bind(this))};f._createTween=function(l){return new h(l)};f.update=function(m){if(this.props.length<1){return
}var l=this.props.map(function(q){var o=q.tween;var n=q.units;var p=o.valueAtTime(m);
p=(n?(p+n):p);return{prop:q.property,value:p}});this._renderer.render(this.el,l);
this.trigger("tween_update",{el:this.el,context:l})};f.getCurrentTime=function(){return this._currentTime
};f.setCurrentTime=function(l){if(l<0||l>this.getDuration()){return}this._currentTime=l;
this.update(this._currentTime)};a.exports=g},{"../Tween":8,"../vendor/utils":24,"./BaseClip":12,"ac-style-renderer":94}],15:[function(c,d,a){var b=c("../vendor/utils");
function g(i,h){h=b.defaults(g.DEFAULTS,(h||{}));this._clip=i;this._startDelay=h.startDelay||0;
this._loop=h.loop||false;this._fill=h.fill||"none"}g.DEFAULTS={fill:"none",loop:false,startDelay:0};
g.FILL_MODES=["none","forwards","backwards","both"];var f=g.prototype;f._show=function(){if(this._isHidden){this._isHidden=false;
this._clip.show()}};f._applyFill=function(n){if(this.getFill()==="none"){return
}var m=this.getDuration();var k=n>m;var j=this.getFill();var i=k&&j==="forwards";
var h=!k&&j==="backwards";var l=j==="both"||i||h;if(l){this._clip.setCurrentTime((k)?m:0)
}};f._hide=function(){if(!this._isHidden){this._isHidden=true;this._clip.hide()
}};f.setEasingDirection=function(h){return this._clip.setEasingDirection(h)};f.on=function(){this._clip.on.apply(this._clip,arguments)
};f.off=function(){this._clip.off.apply(this._clip,arguments)};f.trigger=function(){this._clip.trigger.apply(this._clip,arguments)
};f.getCurrentTime=function(){return this._currentTime};f.setCurrentTime=function(i,h){if(i<0||i>this.getDuration()){this._clip.inEffect=false;
this._applyFill(i)}else{this._clip.inEffect=true;this._clip.setCurrentTime(i,h)
}};f.getDuration=function(){return this._clip.getDuration()};f.getStartDelay=function(){return this._startDelay
};f.setStartDelay=function(h){if(b.isNum(h)){this._startDelay=h}};f.getLoop=function(){return this._loop
};f.setLoop=function(h){this._loop=!!h};f.getFill=function(){return this._fill};
f.setFill=function(i){var h=g.FILL_MODES;if(h.indexOf(i.toLowerCase())!==-1){this._fill=i
}};d.exports=g},{"../vendor/utils":24}],16:[function(c,d,b){var g=c("./BaseClip");
function a(j,i,h){if(typeof j==="object"){h=j;j=h.duration;i=h.props}g.call(this,j,h);
this.props=i||[];this._initializePropEasing();this._lastComputedTime=0;this._easingDirection=1
}a.create=function(h){return new a(h.duration,h.props)};a.validate=function(h){return(Array.isArray(h.props)&&h.props.length>0)
};a.DEFAULT_EASING="linear";var f=a.prototype=new g();f._initializePropEasing=function(){this.props.forEach(function(h){h.easing=this._createEasing(h.easing||g.DEFAULT_EASING)
}.bind(this))};f.setEasingDirection=function(h){this._easingDirection=h};f.update=function(k){var i=(this._easingDirection===-1);
if(this.options.reverseEase!==true){i=false}var j=this.getDuration(),h={};if(this.props.length<1){return
}this.props.forEach(function(n){var m;var l=n.property;if(i){m=n.easing(this.getDuration()-k,n.to,-(n.to-n.from),j)
}else{m=n.easing(k,n.from,(n.to-n.from),j)}h[l]=m}.bind(this));this.trigger("tween_update",h)
};f.getCurrentTime=function(){return this._currentTime};f.setCurrentTime=function(h){if(h<0){h=0
}if(h>this.getDuration()){h=this.getDuration()}if(h<0||h>this.getDuration()){return
}this._currentTime=h;this.update(this._currentTime)};d.exports=a},{"./BaseClip":12}],17:[function(c,d,b){var a=c("../adapters/MediaAsClip");
function f(h,g){if(console){console.warn("VideoClip deprecated, please use adapters/MediaAsClip.")
}return new a(h,g)}d.exports=f},{"../adapters/MediaAsClip":9}],18:[function(c,d,a){if(typeof Object.defineProperties!=="function"){return
}var h=c("ac-event-emitter").EventEmitter;var i=c("../Clock");var b=c("../vendor/utils");
function g(){var j=[].slice.call(arguments);this._mediaElements=j.filter(this._validateMediaElements);
this._clock=new i()}var f=g.prototype=new h();f.addEventListener=f.on;f.removeEventListener=f.off;
f._validateMediaElements=function(j){return(typeof j.play==="function")&&(typeof j.pause==="function")
};f._updateCurrentTime=function(j){this._lastTime=this._clock.currentTime;this._mediaElements.forEach(function(k){k.currentTime=j
})};f._isValidTime=function(j){return(0<=j)&&(j<=this.duration)};f.play=function(){this.paused=false;
this._clock.play();b.invoke(this._mediaElements,"play");this.trigger("play")};f.pause=function(){this.paused=true;
this._clock.pause();b.invoke(this._mediaElements,"pause");this.trigger("pause")
};Object.defineProperties(g.prototype,{paused:{get:function(){return this._paused
},set:function(j){this._paused=!!j}},currentTime:{get:function(){return this._clock.getCurrentTime()
},set:function(j){if(this._isValidTime(j)){this.trigger("seeking",{time:j});this._updateCurrentTime(j);
this.trigger("seeked",{time:j})}}},playbackRate:{get:function(){return this._clock.getPlaybackRate()
},set:function(j){if(!b.isNum(j)){return}this._clock.setPlaybackRate(j);this._mediaElements.forEach(function(k){k.playbackRate=j
});this.trigger("ratechange",{rate:j})}},duration:{get:function(){return this._duration
},set:function(j){this._duration=j}}});d.exports=g},{"../Clock":5,"../vendor/utils":24}],19:[function(b,d,a){var h=b("ac-event-emitter").EventEmitter;
var c=b("../PlayerMonitor");function f(k,i,j){j=j||{};this._player=k;this._monitor=new c(this._player,j);
this._monitor.on("ready",this._initPauses.bind(this,i));this._previousPauseIndex=0;
this._player.addEventListener("play",this._exitPause.bind(this),false)}var g=f.prototype=new h();
g._initPauses=function(i){this._pauses=this._processPauses(i);this._attachPauses(this._pauses)
};g._processPauses=function(i){i=i.filter(function(j){return(0<j)&&(j<this._player.duration)
}.bind(this));i=i.sort(function(k,j){return k-j});if(i[0]!==0){i.unshift(0)}if(i[i.length-1]!==this._player.duration){i.push(this._player.duration)
}return i};g._attachPauses=function(i){i.forEach(function(j){this._monitor.addTime(j,this._enterPause.bind(this))
}.bind(this))};g._enterPause=function(l){var j=l.requested;var i=this._previousPauseIndex;
var k=this._pauses.indexOf(j);if(i===k){return}this._atPausePoint=true;this._player.pause();
this._player.currentTime=j;this.trigger("pauseenter",{from:i,to:k});this._previousPauseIndex=k
};g._exitPause=function(){var k=this._player.currentTime;var j=this._forwards();
var l=j&&k===this._player.duration;var i=!j&&k===0;if(this._atPausePoint&&!(l||i)){this._atPausePoint=false;
this.trigger("pauseexit",{from:this._previousPauseIndex,to:this._calcNextPauseIndex()})
}};g._forwards=function(){return this._player.playbackRate>0};g._calcNextPauseIndex=function(){var i=this._previousPauseIndex;
var j=this._forwards();return i+((j)?1:-1)};d.exports=f},{"../PlayerMonitor":6}],20:[function(d,f,b){var h=d("ac-event-emitter").EventEmitter;
var i=d("../Clock");var c=d("../adapters/PlayerAsMedia");function a(k,j){j=j||{};
if(!k){throw new TypeError("BasicPlayer: Invalid clip provided",k)}this._clip=k;
this._paused=true;this.setClock(j.clock||new i());window.setTimeout(this._triggerStart.bind(this),0)
}var g=a.prototype=new h();g.addEventListener=g.on;g.removeEventListener=g.off;
g.play=function(){this._paused=false;this._clock.play();this._update();this.trigger("play")
};g.pause=function(){this.setPaused(true);this._clock.pause();this.trigger("pause")
};g._triggerStart=function(){this.trigger("canplay");this.trigger("canplaythrough")
};g._updateCurrentTime=function(j){this._clock.setCurrentTime(j);this._lastTime=this._clip.setCurrentTime(j)
};g._update=function(){var m=this._clock.getCurrentTime();var n=this.getDuration();
var l=this._clock.getPlaybackRate();var k=l>0;var o=k&&m>=n;var j=!k&&m<=0;if(o||j){m=(o)?n:0;
this.pause();this._updateCurrentTime(m)}this.trigger("timeupdate",{previous:this._lastTime,time:m});
if(o){this.trigger("ended")}if(j){this.trigger("returned")}if(!this.isPaused()){this._updateCurrentTime(m);
window.requestAnimationFrame(this._update.bind(this))}};g._isValidTime=function(j){return(0<=j)&&(j<=this.getDuration())
};g.asMedia=function(){return new c(this)};g.isPaused=function(){return this._paused
};g.setPaused=function(j){this._paused=!!j};g.getCurrentTime=function(){return this._clock.getCurrentTime()
};g.setCurrentTime=function(j){if(this._isValidTime(j)){this.trigger("seeking",{time:j});
this._updateCurrentTime(j);this.trigger("seeked",{time:j})}};g.getPlaybackRate=function(){return this._clock.getPlaybackRate()
};g.setPlaybackRate=function(j){this._clock.setPlaybackRate(j);this.trigger("ratechange",{rate:j})
};g.getDuration=function(){return this._clip.getDuration()};g.setClock=function(j){this._clock=j
};g.getClock=function(){return this._clock};f.exports=a},{"../Clock":5,"../adapters/PlayerAsMedia":10}],21:[function(d,f,c){var b=d("./BasicPlayer");
function a(h,g){var i=new b(h,g);if(console){console.warn("MediaPlayer module deprecated, please use adapters/PlayerAsMedia or #toMedia method on instances of BasicPlayer")
}return i.asMedia()}f.exports=a},{"./BasicPlayer":20}],22:[function(q,d,J){var w={linear:function E(N,L,M,K){return M*N/K+L
},easeInQuad:function n(N,L,M,K){return M*(N/=K)*N+L},easeOutQuad:function b(N,L,M,K){return -M*(N/=K)*(N-2)+L
},easeInOutQuad:function x(N,L,M,K){if((N/=K/2)<1){return M/2*N*N+L}return -M/2*((--N)*(N-2)-1)+L
},easeInCubic:function t(N,L,M,K){return M*(N/=K)*N*N+L},easeOutCubic:function i(N,L,M,K){return M*((N=N/K-1)*N*N+1)+L
},easeInOutCubic:function h(N,L,M,K){if((N/=K/2)<1){return M/2*N*N*N+L}return M/2*((N-=2)*N*N+2)+L
},easeInQuart:function j(N,L,M,K){return M*(N/=K)*N*N*N+L},easeOutQuart:function I(N,L,M,K){return -M*((N=N/K-1)*N*N*N-1)+L
},easeInOutQuart:function G(N,L,M,K){if((N/=K/2)<1){return M/2*N*N*N*N+L}return -M/2*((N-=2)*N*N*N-2)+L
},easeInQuint:function m(N,L,M,K){return M*(N/=K)*N*N*N*N+L},easeOutQuint:function a(N,L,M,K){return M*((N=N/K-1)*N*N*N*N+1)+L
},easeInOutQuint:function H(N,L,M,K){if((N/=K/2)<1){return M/2*N*N*N*N*N+L}return M/2*((N-=2)*N*N*N*N+2)+L
},easeInSine:function r(N,L,M,K){return -M*Math.cos(N/K*(Math.PI/2))+M+L},easeOutSine:function f(N,L,M,K){return M*Math.sin(N/K*(Math.PI/2))+L
},easeInOutSine:function A(N,L,M,K){return -M/2*(Math.cos(Math.PI*N/K)-1)+L},easeInExpo:function c(N,L,M,K){return(N===0)?L:M*Math.pow(2,10*(N/K-1))+L
},easeOutExpo:function D(N,L,M,K){return(N===K)?L+M:M*(-Math.pow(2,-10*N/K)+1)+L
},easeInOutExpo:function p(N,L,M,K){if(N===0){return L}if(N===K){return L+M}if((N/=K/2)<1){return M/2*Math.pow(2,10*(N-1))+L
}return M/2*(-Math.pow(2,-10*--N)+2)+L},easeInCirc:function s(N,L,M,K){return -M*(Math.sqrt(1-(N/=K)*N)-1)+L
},easeOutCirc:function g(N,L,M,K){return M*Math.sqrt(1-(N=N/K-1)*N)+L},easeInOutCirc:function B(N,L,M,K){if((N/=K/2)<1){return -M/2*(Math.sqrt(1-N*N)-1)+L
}return M/2*(Math.sqrt(1-(N-=2)*N)+1)+L},easeInElastic:function z(O,Q,M,P){var L=1.70158;
var N=0;var K=M;if(O===0){return Q}if((O/=P)===1){return Q+M}if(!N){N=P*0.3}if(K<Math.abs(M)){K=M;
L=N/4}else{L=N/(2*Math.PI)*Math.asin(M/K)}return -(K*Math.pow(2,10*(O-=1))*Math.sin((O*P-L)*(2*Math.PI)/N))+Q
},easeOutElastic:function y(O,Q,M,P){var L=1.70158;var N=0;var K=M;if(O===0){return Q
}if((O/=P)===1){return Q+M}if(!N){N=P*0.3}if(K<Math.abs(M)){K=M;L=N/4}else{L=N/(2*Math.PI)*Math.asin(M/K)
}return K*Math.pow(2,-10*O)*Math.sin((O*P-L)*(2*Math.PI)/N)+M+Q},easeInOutElastic:function C(O,Q,M,P){var L=1.70158;
var N=0;var K=M;if(O===0){return Q}if((O/=P/2)===2){return Q+M}if(!N){N=P*(0.3*1.5)
}if(K<Math.abs(M)){K=M;L=N/4}else{L=N/(2*Math.PI)*Math.asin(M/K)}if(O<1){return -0.5*(K*Math.pow(2,10*(O-=1))*Math.sin((O*P-L)*(2*Math.PI)/N))+Q
}return K*Math.pow(2,-10*(O-=1))*Math.sin((O*P-L)*(2*Math.PI)/N)*0.5+M+Q},easeInBack:function v(N,K,M,O,L){if(L===undefined){L=1.70158
}return M*(N/=O)*N*((L+1)*N-L)+K},easeOutBack:function l(N,K,M,O,L){if(L===undefined){L=1.70158
}return M*((N=N/O-1)*N*((L+1)*N+L)+1)+K},easeInOutBack:function F(N,K,M,O,L){if(L===undefined){L=1.70158
}if((N/=O/2)<1){return M/2*(N*N*(((L*=(1.525))+1)*N-L))+K}return M/2*((N-=2)*N*(((L*=(1.525))+1)*N+L)+2)+K
},easeInBounce:function u(N,L,M,K){return M-w.easeOutBounce(K-N,0,M,K)+L},easeOutBounce:function k(N,L,M,K){if((N/=K)<(1/2.75)){return M*(7.5625*N*N)+L
}else{if(N<(2/2.75)){return M*(7.5625*(N-=(1.5/2.75))*N+0.75)+L}else{if(N<(2.5/2.75)){return M*(7.5625*(N-=(2.25/2.75))*N+0.9375)+L
}else{return M*(7.5625*(N-=(2.625/2.75))*N+0.984375)+L}}}},easeInOutBounce:function o(N,L,M,K){if(N<K/2){return w.easeInBounce(N*2,0,M,K)*0.5+L
}return w.easeOutBounce(N*2-K,0,M,K)*0.5+M*0.5+L}};d.exports=w},{}],23:[function(b,c,a){
/*! MIT License
 *
 * KeySpline - use bezier curve for transition easing function
 * Copyright (c) 2012 Gaetan Renaudeau <renaudeau.gaetan@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
function d(o,l,n,j){this.get=function(p){if(o===l&&n===j){return p
}return g(k(p),l,j)};function i(p,q){return 1-3*q+3*p}function h(p,q){return 3*q-6*p
}function f(p){return 3*p}function g(r,p,q){return((i(p,q)*r+h(p,q))*r+f(p))*r}function m(r,p,q){return 3*i(p,q)*r*r+2*h(p,q)*r+f(p)
}function k(s){var q=s;for(var r=0;r<4;++r){var t=m(q,o,n);if(t===0){return q}var p=g(q,o,n)-s;
q-=p/t}return q}}c.exports=d},{}],24:[function(b,c,a){c.exports={isNum:function(d){return typeof d==="number"
},isArray:function(f){var d=Object.prototype.toString;return d.call(f)==="[object Array]"
},addClass:function(d,f){d.classList.add(f)},removeClass:function(d,f){d.classList.remove(f)
},hasClass:function(d,f){return d.contains(f)},defaults:function(g,f){var d={};
f=f||{};for(var h in g){if(g.hasOwnProperty(h)){d[h]=(f[h]!=null)?f[h]:g[h]}}return d
},defaultProps:function(h,g,d){var f=this.defaults(g,d);for(var i in f){if(f.hasOwnProperty(i)){h[i]=f[i]
}}},invoke:function(g,d){var f=[].slice.call(arguments,2);if(!Array.isArray(g)){throw new Error("List is not an array")
}g.forEach(function(h){var i=h[d];if(i&&typeof i==="function"){i.apply(h,f)}})}}
},{}],25:[function(b,c,a){c.exports.DOMEmitter=b("./ac-dom-emitter/DOMEmitter")
},{"./ac-dom-emitter/DOMEmitter":26}],26:[function(b,c,a){var g;var f=b("ac-event-emitter").EventEmitter;
var d="dom-emitter";function h(i){if(i===null){return}this.el=i;this._bindings={};
this._eventEmitter=new f()}g=h.prototype;g._parseEventNames=function(i){if(!i){return[i]
}return i.split(" ")};g._onListenerEvent=function(j,i){this.trigger(j,i,false)};
g._setListener=function(i){this._bindings[i]=this._onListenerEvent.bind(this,i);
this._addEventListener(i,this._bindings[i])};g._removeListener=function(i){this._removeEventListener(i,this._bindings[i]);
delete this._bindings[i]};g._addEventListener=function(j,k,i){if(this.el.addEventListener){this.el.addEventListener(j,k,i)
}else{if(this.el.attachEvent){this.el.attachEvent("on"+j,k)}else{target["on"+j]=k
}}return this};g._removeEventListener=function(j,k,i){if(this.el.removeEventListener){this.el.removeEventListener(j,k,i)
}else{this.el.detachEvent("on"+j,k)}return this};g._triggerInternalEvent=function(i,j){this.trigger(d+":"+i,j)
};g.on=function(i,k,j){i=this._parseEventNames(i);i.forEach(function(n,m,l){if(!this.has(l)){this._setListener(l)
}this._triggerInternalEvent("willon",{evt:l,callback:n,context:m});this._eventEmitter.on(l,n,m);
this._triggerInternalEvent("didon",{evt:l,callback:n,context:m})}.bind(this,k,j));
return this};g.off=function(i,l,k){var j=Array.prototype.slice.call(arguments,0);
i=this._parseEventNames(i);i.forEach(function(q,p,n,m){if(n.length===0){this._eventEmitter.off();
var o;for(o in this._bindings){if(this._bindings.hasOwnProperty(o)){this._removeListener(o)
}}return}this._triggerInternalEvent("willoff",{evt:m,callback:q,context:p});this._eventEmitter.off(m,q,p);
this._triggerInternalEvent("didoff",{evt:m,callback:q,context:p});if(!this.has(m)){this._removeListener(m)
}}.bind(this,l,k,j));return this};g.once=function(i,k,j){i=this._parseEventNames(i);
i.forEach(function(n,m,l){if(!this.has(l)){this._setListener(l)}this._triggerInternalEvent("willonce",{evt:l,callback:n,context:m});
this._eventEmitter.once.call(this,l,n,m);this._triggerInternalEvent("didonce",{evt:l,callback:n,context:m})
}.bind(this,k,j));return this};g.has=function(i,k,j){if(this._eventEmitter&&this._eventEmitter.has.apply(this._eventEmitter,arguments)){return true
}return false};g.trigger=function(i,j,k){i=this._parseEventNames(i);i.forEach(function(m,n,l){this._eventEmitter.trigger(l,m,n)
}.bind(this,j,k));return this};g.destroy=function(){this._triggerInternalEvent("willdestroy");
this.off();this.el=this._eventEmitter=this._bindings=null};c.exports=h},{}],27:[function(i,c,x){var s=Object.prototype.toString;
var l=Object.prototype.hasOwnProperty;var b=typeof Array.prototype.indexOf==="function"?function(z,A){return z.indexOf(A)
}:function(z,B){for(var A=0;A<z.length;A++){if(z[A]===B){return A}}return -1};var k=Array.isArray||function(z){return s.call(z)=="[object Array]"
};var v=Object.keys||function(B){var z=[];for(var A in B){if(B.hasOwnProperty(A)){z.push(A)
}}return z};var u=typeof Array.prototype.forEach==="function"?function(z,A){return z.forEach(A)
}:function(z,B){for(var A=0;A<z.length;A++){B(z[A])}};var m=function(z,D,A){if(typeof z.reduce==="function"){return z.reduce(D,A)
}var C=A;for(var B=0;B<z.length;B++){C=D(C,z[B])}return C};var y=/^[0-9]+$/;function d(C,B){if(C[B].length==0){return C[B]={}
}var A={};for(var z in C[B]){if(l.call(C[B],z)){A[z]=C[B][z]}}C[B]=A;return A}function q(D,B,A,E){var z=D.shift();
if(l.call(Object.prototype,A)){return}if(!z){if(k(B[A])){B[A].push(E)}else{if("object"==typeof B[A]){B[A]=E
}else{if("undefined"==typeof B[A]){B[A]=E}else{B[A]=[B[A],E]}}}}else{var C=B[A]=B[A]||[];
if("]"==z){if(k(C)){if(""!=E){C.push(E)}}else{if("object"==typeof C){C[v(C).length]=E
}else{C=B[A]=[B[A],E]}}}else{if(~b(z,"]")){z=z.substr(0,z.length-1);if(!y.test(z)&&k(C)){C=d(B,A)
}q(D,C,z,E)}else{if(!y.test(z)&&k(C)){C=d(B,A)}q(D,C,z,E)}}}}function f(D,C,G){if(~b(C,"]")){var F=C.split("["),z=F.length,E=z-1;
q(F,D,"base",G)}else{if(!y.test(C)&&k(D.base)){var B={};for(var A in D.base){B[A]=D.base[A]
}D.base=B}n(D.base,C,G)}return D}function o(C){if("object"!=typeof C){return C}if(k(C)){var z=[];
for(var B in C){if(l.call(C,B)){z.push(C[B])}}return z}for(var A in C){C[A]=o(C[A])
}return C}function g(A){var z={base:{}};u(v(A),function(B){f(z,B,A[B])});return o(z.base)
}function h(A){var z=m(String(A).split("&"),function(B,F){var G=b(F,"="),E=t(F),C=F.substr(0,E||G),D=F.substr(E||G,F.length),D=D.substr(b(D,"=")+1,D.length);
if(""==C){C=F,D=""}if(""==C){return B}return f(B,p(C),p(D))},{base:{}}).base;return o(z)
}x.parse=function(z){if(null==z||""==z){return{}}return"object"==typeof z?g(z):h(z)
};var r=x.stringify=function(A,z){if(k(A)){return j(A,z)}else{if("[object Object]"==s.call(A)){return w(A,z)
}else{if("string"==typeof A){return a(A,z)}else{return z+"="+encodeURIComponent(String(A))
}}}};function a(A,z){if(!z){throw new TypeError("stringify expects an object")}return z+"="+encodeURIComponent(A)
}function j(z,C){var A=[];if(!C){throw new TypeError("stringify expects an object")
}for(var B=0;B<z.length;B++){A.push(r(z[B],C+"["+B+"]"))}return A.join("&")}function w(F,E){var A=[],D=v(F),C;
for(var B=0,z=D.length;B<z;++B){C=D[B];if(""==C){continue}if(null==F[C]){A.push(encodeURIComponent(C)+"=")
}else{A.push(r(F[C],E?E+"["+encodeURIComponent(C)+"]":encodeURIComponent(C)))}}return A.join("&")
}function n(B,A,C){var z=B[A];if(l.call(Object.prototype,A)){return}if(undefined===z){B[A]=C
}else{if(k(z)){z.push(C)}else{B[A]=[z,C]}}}function t(C){var z=C.length,B,D;for(var A=0;
A<z;++A){D=C[A];if("]"==D){B=false}if("["==D){B=true}if("="==D&&!B){return A}}}function p(A){try{return decodeURIComponent(A.replace(/\+/g," "))
}catch(z){return A}}},{}],28:[function(b,c,a){c.exports={clone:b("./ac-object/clone"),defaults:b("./ac-object/defaults"),extend:b("./ac-object/extend"),getPrototypeOf:b("./ac-object/getPrototypeOf"),isEmpty:b("./ac-object/isEmpty"),toQueryParameters:b("./ac-object/toQueryParameters")}
},{"./ac-object/clone":29,"./ac-object/defaults":30,"./ac-object/extend":31,"./ac-object/getPrototypeOf":32,"./ac-object/isEmpty":33,"./ac-object/toQueryParameters":34}],29:[function(b,c,a){var f=b("./extend");
c.exports=function d(g){return f({},g)}},{"./extend":31}],30:[function(b,c,a){var f=b("./extend");
c.exports=function d(h,g){if(typeof h!=="object"||typeof g!=="object"){throw new TypeError("defaults: must provide a defaults and options object")
}return f({},h,g)}},{"./extend":31}],31:[function(c,d,b){var a=Object.prototype.hasOwnProperty;
d.exports=function f(){var h;var g;if(arguments.length<2){h=[{},arguments[0]]}else{h=[].slice.call(arguments)
}g=h.shift();h.forEach(function(j){if(j!=null){for(var i in j){if(a.call(j,i)){g[i]=j[i]
}}}});return g}},{}],32:[function(c,d,b){var a=Object.prototype.hasOwnProperty;
d.exports=function f(i){if(Object.getPrototypeOf){return Object.getPrototypeOf(i)
}else{if(typeof i!=="object"){throw new Error("Requested prototype of a value that is not an object.")
}else{if(typeof this.__proto__==="object"){return i.__proto__}else{var g=i.constructor;
var h;if(a.call(i,"constructor")){h=g;if(!(delete i.constructor)){return null}g=i.constructor;
i.constructor=h}return g?g.prototype:null}}}}},{}],33:[function(c,d,b){var a=Object.prototype.hasOwnProperty;
d.exports=function f(g){var h;if(typeof g!=="object"){throw new TypeError("ac-base.Object.isEmpty : Invalid parameter - expected object")
}for(h in g){if(a.call(g,h)){return false}}return true}},{}],34:[function(c,f,b){var a=c("qs");
f.exports=function d(g){if(typeof g!=="object"){throw new TypeError("toQueryParameters error: argument is not an object")
}return a.stringify(g)}},{qs:27}],35:[function(b,c,a){c.exports.WindowDelegate=b("./window-delegate/WindowDelegate");
c.exports.windowEmitter=b("./window-delegate/windowEmitter")},{"./window-delegate/WindowDelegate":36,"./window-delegate/windowEmitter":37}],36:[function(c,f,a){var g;
var b=c("./windowEmitter");function d(){this._emitter=b;this._setWindowDimensionValues();
this._setScrollValues();this.on("resize",this._setWindowDimensionValues.bind(this));
this.on("scroll",this._setScrollValues.bind(this));this.on("touchstart",this._touchScrollStart.bind(this));
this.on("touchend",this._setZoomValues.bind(this))}g=d.prototype;g.on=function(){this._emitter.on.apply(this._emitter,arguments);
return this};g.once=function(){this._emitter.once.apply(this._emitter,arguments);
return this};g.off=function(){this._emitter.off.apply(this._emitter,arguments);
return this};g.has=function(){return this._emitter.has.apply(this._emitter,arguments)
};g.trigger=function(){this._emitter.trigger.apply(this._emitter,arguments);return this
};g.propagateTo=function(){this._emitter.propagateTo.apply(this._emitter,arguments);
return this};g.stopPropagatingTo=function(){this._emitter.stopPropagatingTo.apply(this._emitter,arguments);
return this};g.isZoomed=function(){return this.clientWidth>this.innerWidth};g._setWindowDimensionValues=function(){this.clientWidth=document.documentElement.clientWidth;
this.clientHeight=document.documentElement.clientHeight;this.innerWidth=window.innerWidth||this.clientWidth;
this.innerHeight=window.innerHeight||this.clientHeight};g._setZoomValues=function(){var h=this.innerWidth;
this.innerWidth=window.innerWidth;if(h!==this.innerWidth){this.innerHeight=window.innerHeight;
this.trigger("zoom");if(h<this.innerWidth){this.trigger("zoomIn")}else{this.trigger("zoomOut")
}}else{setTimeout(this._setZoomValues.bind(this),500)}};g._updateScrollX=function(){this.scrollX=(window.pageXOffset!==undefined)?window.pageXOffset:(document.documentElement||document.body.parentNode||document.body).scrollLeft;
this.maxScrollX=document.body.scrollWidth-this.innerWidth;return this.scrollX};
g._updateScrollY=function(){this.scrollY=(window.pageYOffset!==undefined)?window.pageYOffset:(document.documentElement||document.body.parentNode||document.body).scrollTop;
this.maxScrollY=document.body.scrollHeight-this.innerHeight;return this.scrollY
};g._setScrollValues=function(){var i=this.scrollX,h=this.scrollY;this._updateScrollX();
this._updateScrollY();if(this.scrollX!==i){this.trigger("scrollX")}if(this.scrollY!==h){this.trigger("scrollY")
}this._scrollStop()};g._scrollStop=function(){if(typeof window.ontouchstart==="undefined"){if(this._scrollStopTimer){clearTimeout(this._scrollStopTimer)
}this._scrollStopTimer=setTimeout(function(){clearTimeout(this._scrollStopTimer);
this.trigger("scrollStop")}.bind(this),300)}};g._touchScrollStart=function(){this._updateScrollX();
this._updateScrollY();this.once("touchend",this._touchScrollStop.bind(this,this.scrollX,this.scrollY))
};g._touchScrollStop=function(i,h,j){this._updateScrollX();this._updateScrollY();
if(i!==this.scrollX||h!==this.scrollY){setTimeout(this._touchScrollStop.bind(this,this.scrollX,this.scrollY,true),300)
}else{if(j){this.trigger("scrollStop")}}};f.exports=new d()},{"./windowEmitter":37}],37:[function(b,c,a){var d=b("ac-dom-emitter").DOMEmitter;
c.exports=new d(window)},{"ac-dom-emitter":25}],38:[function(b,c,a){var d=b("./ac-element-tracker/ElementTracker");
c.exports=new d();c.exports.ElementTracker=d},{"./ac-element-tracker/ElementTracker":39}],39:[function(c,b,g){var h;
var f=c("ac-object");var i=c("ac-base").Element;var k=c("ac-base").Array;var m=c("window-delegate").WindowDelegate;
var j=c("./TrackedElement");var d={autoStart:false};function a(o,n){this.options=f.clone(d);
this.options=typeof n==="object"?f.extend(this.options,n):this.options;this.windowDelegate=m;
this.tracking=false;this.elements=[];if(o&&(Array.isArray(o)||this._isNodeList(o)||i.isElement(o))){this.addElements(o)
}if(this.options.autoStart===true){this.start()}}h=a.prototype;var l=/^\[object (HTMLCollection|NodeList|Object)\]$/;
h._isNodeList=function(n){if(!n){return false}if(typeof n.length!=="number"){return false
}if(typeof n[0]==="object"&&(!n[0]||!n[0].nodeType)){return false}return l.test(Object.prototype.toString.call(n))
};h._registerElements=function(n){n=[].concat(n);n.forEach(function(p){if(this._elementInDOM(p)){var o=new j(p);
o.offsetTop=o.element.offsetTop;this.elements.push(o)}},this)};h._registerTrackedElementObjects=function(o){var n=[].concat(o);
n.forEach(function(p){if(this._elementInDOM(p.element)){p.offsetTop=p.element.offsetTop;
this.elements.push(p)}},this)};h._elementInDOM=function(p){var o=false;var n=document.getElementsByTagName("body")[0];
if(i.isElement(p)&&n.contains(p)){o=true}return o};h._onScroll=function(){this.elements.forEach(function(n){this.refreshElementState(n)
},this)};h._onResize=function(){this.elements.forEach(function(n){this.refreshElementState(n)
},this)};h._elementPercentInView=function(n){return n.pixelsInView/n.height};h._elementPixelsInView=function(o){var r=0;
var q=o.top;var p=o.bottom;var n=this.windowDelegate.innerHeight;if(q<=0&&p>=n){r=n
}else{if(q>=0&&q<n&&p>n){r=n-q}else{if(q<0&&(p<n&&p>=0)){r=o.bottom}else{if(q>=0&&p<=n){r=o.height
}}}}return r};h._isElementOrObject=function(n){return n&&(i.isElement(n)||(typeof n==="object"&&!Array.isArray(n)&&!this._isNodeList(n)))
};h._ifInView=function(n,p,o){if(!p){n.trigger("enterview",n)}if(!o&&n.percentInView>n.inViewThreshold){n.inThreshold=true;
n.trigger("thresholdenter",n)}};h._ifAlreadyInView=function(n,o){if(!n.inView){n.trigger("exitview",n)
}if(o&&n.percentInView<n.inViewThreshold){n.inThreshold=false;n.trigger("thresholdexit",n)
}};h.addElements=function(n){n=this._isNodeList(n)?k.toArray(n):[].concat(n);n.forEach(function(o){this.addElement(o)
},this)};h.addElement=function(o){var n;if(this._isElementOrObject(o)){n=new j(o);
this._registerTrackedElementObjects(n)}else{throw new TypeError("ElementTracker.addElement: "+o+"must be a valid Element or Object")
}return n};h.removeElement=function(p){var o=[];var n;this.elements.forEach(function(q,r){if(q===p||q.element===p){o.push(r)
}});n=this.elements.filter(function(r,q){return o.indexOf(q)<0?true:false});this.elements=n
};h.stop=function(){if(this.tracking===true){this.tracking=false;this.windowDelegate.off("scroll",this._onScroll);
this.windowDelegate.off("resize",this._onResize)}};h.start=function(){if(this.tracking===false){this.tracking=true;
this.windowDelegate.on("scroll",this._onScroll,this);this.windowDelegate.on("resize",this._onResize,this);
this.refreshAllElementStates()}};h.refreshAllElementStates=function(){this.elements.forEach(function(n){this.refreshElementState(n)
},this)};h.refreshElementState=function(n){var p=i.getBoundingBox(n.element);var q=n.inView;
var o=n.inThreshold;n=f.extend(n,p);n.pixelsInView=this._elementPixelsInView(n);
n.percentInView=this._elementPercentInView(n);n.inView=n.pixelsInView>0;if(n.inView){this._ifInView(n,q,o)
}if(q){this._ifAlreadyInView(n,o)}return n};b.exports=a},{"./TrackedElement":40,"ac-base":false,"ac-object":28,"window-delegate":35}],40:[function(b,c,a){var d;
var h=b("ac-dom-emitter").DOMEmitter;var g={inViewThreshold:0.75};function f(j){var i={};
var k;if(j.nodeType&&j.nodeType>0){i.element=j}else{i=j}for(k in g){this[k]=g[k]
}for(k in i){this[k]=i[k]}this.inView=false;this.inThreshold=false;this.percentInView=0;
this.pixelsInView=0;this.offsetTop=0;this.top=0;this.right=0;this.bottom=0;this.left=0;
this.width=0;this.height=0;h.call(this,i.element)}d=f.prototype=new h(null);c.exports=f
},{"ac-dom-emitter":25}],41:[function(c,d,b){var a=c("./ac-keyboard/Keyboard");
d.exports=new a();d.exports.Keyboard=a;d.exports.keys=c("./ac-keyboard/keymap")
},{"./ac-keyboard/Keyboard":43,"./ac-keyboard/keymap":44}],42:[function(d,f,b){var c=d("ac-base").Object;
var a=["keyLocation"];function g(h){this.originalEvent=h;for(var i in h){if(typeof h[i]!=="function"&&a.indexOf(i)===-1){this[i]=h[i]
}}this.location=(this.originalEvent.keyLocation===undefined)?this.originalEvent.location:this.originalEvent.keyLocation
}g.prototype={preventDefault:function(){if(typeof this.originalEvent.preventDefault!=="function"){this.originalEvent.returnValue=false;
return}return this.originalEvent.preventDefault()},stopPropagation:function(){return this.originalEvent.stopPropagation()
}};f.exports=g},{"ac-base":false}],43:[function(f,c,h){var j=f("ac-base").Element;
var g=f("./KeyEvent");var n=f("ac-event-emitter").EventEmitter;var k=f("./keymap");
var l=0;var d=1;var a=2;var m=3;var i;function b(){this._keysDown=[];this._keyDownEmitter=new n();
this._keyUpEmitter=new n();j.addEventListener(document,"keydown",this._DOMKeyDown.bind(this),true);
j.addEventListener(document,"keyup",this._DOMKeyUp.bind(this),true);this._listening=[]
}i=b.prototype;i._castEventNameNumberToString=function(o){if(typeof o==="number"){return o.toString()
}return o};i._DOMKeyDown=function(p){var o=this._normalizeKeyboardEvent(p);var q=o.keyCode;
this._trackKeyDown(q);this._keyDownEmitter.trigger(q.toString(),o)};i._DOMKeyUp=function(p){var o=this._normalizeKeyboardEvent(p);
var q=o.keyCode;this._trackKeyUp(q);this._keyUpEmitter.trigger(q.toString(),o)};
i.addKeyDown=function(){var o=Array.prototype.slice.call(arguments);var p=o.shift();
if(p===undefined){throw new TypeError('Could not listen for keyup event on "'+p+'"')
}p=this._castEventNameNumberToString(p);return this._keyDownEmitter.on.apply(this._keyDownEmitter,[p].concat(o))
};i.addKeyUp=function(){var o=Array.prototype.slice.call(arguments);var p=o.shift();
if(p===undefined){throw new TypeError('Could not listen for keyup event on "'+p+'"')
}p=this._castEventNameNumberToString(p);return this._keyUpEmitter.on.apply(this._keyUpEmitter,[p].concat(o))
};i.removeKeyDown=function(){var o=Array.prototype.slice.call(arguments);var p=o.shift();
p=this._castEventNameNumberToString(p);return this._keyDownEmitter.off.apply(this._keyDownEmitter,[p].concat(o))
};i.removeKeyUp=function(){var o=Array.prototype.slice.call(arguments);var p=o.shift();
p=this._castEventNameNumberToString(p);return this._keyUpEmitter.off.apply(this._keyUpEmitter,[p].concat(o))
};i.isDown=function(o){return(this._keysDown.indexOf(o)!==-1)};i.isUp=function(o){return !this.isDown(o)
};i._trackKeyUp=function(p){var o=this._keysDown.indexOf(p);if(o!==-1){this._keysDown.splice(o,1)
}};i._trackKeyDown=function(o){if(this._keysDown.indexOf(o)===-1){this._keysDown.push(o)
}};i._normalizeKeyboardEvent=function(o){return new g(o)};c.exports=b},{"./KeyEvent":42,"./keymap":44,"ac-base":false}],44:[function(b,c,a){c.exports={BACKSPACE:8,TAB:9,ENTER:13,SHIFT:16,CONTROL:17,ALT:18,COMMAND:91,CAPSLOCK:20,ESCAPE:27,PAGE_UP:33,PAGE_DOWN:34,END:35,HOME:36,ARROW_LEFT:37,ARROW_UP:38,ARROW_RIGHT:39,ARROW_DOWN:40,DELETE:46,ZERO:48,ONE:49,TWO:50,THREE:51,FOUR:52,FIVE:53,SIX:54,SEVEN:55,EIGHT:56,NINE:57,A:65,B:66,C:67,D:68,E:69,F:70,G:71,H:72,I:73,J:74,K:75,L:76,M:77,N:78,O:79,P:80,Q:81,R:82,S:83,T:84,U:85,V:86,W:87,X:88,Y:89,Z:90,NUMPAD_ZERO:96,NUMPAD_ONE:97,NUMPAD_TWO:98,NUMPAD_THREE:99,NUMPAD_FOUR:100,NUMPAD_FIVE:101,NUMPAD_SIX:102,NUMPAD_SEVEN:103,NUMPAD_EIGHT:104,NUMPAD_NINE:105,NUMPAD_ASTERISK:106,NUMPAD_PLUS:107,NUMPAD_DASH:109,NUMPAD_DOT:110,NUMPAD_SLASH:111,NUMPAD_EQUALS:187,TICK:192,LEFT_BRACKET:219,RIGHT_BRACKET:221,BACKSLASH:220,SEMICOLON:186,APOSTRAPHE:222,SPACEBAR:32,CLEAR:12,COMMA:188,DOT:190,SLASH:191}
},{}],45:[function(b,c,a){c.exports=b(27)},{}],46:[function(b,c,a){c.exports={clone:b("./ac-object/clone"),create:b("./ac-object/create"),defaults:b("./ac-object/defaults"),extend:b("./ac-object/extend"),getPrototypeOf:b("./ac-object/getPrototypeOf"),isDate:b("./ac-object/isDate"),isEmpty:b("./ac-object/isEmpty"),isRegExp:b("./ac-object/isRegExp"),toQueryParameters:b("./ac-object/toQueryParameters")}
},{"./ac-object/clone":47,"./ac-object/create":48,"./ac-object/defaults":49,"./ac-object/extend":50,"./ac-object/getPrototypeOf":51,"./ac-object/isDate":52,"./ac-object/isEmpty":53,"./ac-object/isRegExp":54,"./ac-object/toQueryParameters":55}],47:[function(b,c,a){c.exports=b(29)
},{"./extend":50}],48:[function(b,d,a){var f=function(){};d.exports=function c(g){if(arguments.length>1){throw new Error("Second argument not supported")
}if(g===null||typeof g!=="object"){throw new TypeError("Object prototype may only be an Object.")
}if(typeof Object.create==="function"){return Object.create(g)}else{f.prototype=g;
return new f()}}},{}],49:[function(b,c,a){var f=b("./extend");c.exports=function d(h,g){if(typeof h!=="object"){throw new TypeError("defaults: must provide a defaults object")
}g=g||{};if(typeof g!=="object"){throw new TypeError("defaults: options must be a typeof object")
}return f({},h,g)}},{"./extend":50}],50:[function(b,c,a){c.exports=b(31)},{}],51:[function(b,c,a){c.exports=b(32)
},{}],52:[function(b,d,a){d.exports=function c(f){return Object.prototype.toString.call(f)==="[object Date]"
}},{}],53:[function(b,c,a){c.exports=b(33)},{}],54:[function(c,d,b){d.exports=function a(f){return window.RegExp?f instanceof RegExp:false
}},{}],55:[function(b,c,a){c.exports=b(34)},{qs:45}],56:[function(b,c,a){c.exports={Keyframe:b("./ac-keyframe/Keyframe"),Interpolation:b("./ac-keyframe/Interpolation")}
},{"./ac-keyframe/Interpolation":57,"./ac-keyframe/Keyframe":58}],57:[function(b,c,a){var f=b("ac-animation-sequencer").Timeline;
function d(){this._start=null;this._end=null;this._duration=null}d.prototype={_mergeToClip:function(){var i=this._start;
var j=this._end;var g=this._duration;var h=function(l){var k={element:l.element,clip:l.clipType||"Element",duration:g,props:[]};
l.props.forEach(function(o){var n={property:o.property,from:o.value,to:o.value,easing:o.easing||"linear"};
if(o.units){n.units=o.units}var m=i.findStyle(l.element,o.property);if(m){n.from=m.value
}k.props.push(n)});return k};return j.getStyles().map(h)},setStartKeyframe:function(g){this._start=g;
return this},setEndKeyframe:function(g){this._end=g;return this},setDuration:function(g){this._duration=g;
return this},getClip:function(){return f.create(this._mergeToClip())}};c.exports=d
},{"ac-animation-sequencer":4}],58:[function(c,d,a){var h=c("./helper/isTransformProperty");
var i=c("ac-deferred");var b=c("ac-object");var g=c("ac-animation-sequencer").Timeline;
function f(l,k,j){this.id=l;this._styles=k;this.options=j||{}}f.prototype={clone:function(){return new f(this.id,this._styles,this.options)
},findStyle:function(k,l){var j=null;this._styles.forEach(function(m){if(m.element===k){m.props.forEach(function(n){if(n.property===l){j=n
}})}});return j},getStyles:function(){return this._styles},__rafDraw:function(j,k){window.requestAnimationFrame(function(){j.update(j.getDuration());
k.resolve()})},draw:function(){var j=[];this.getStyles().forEach(function(m){var l=m.clipType||"Element";
var k=g.clipTypes[l];var o=[];var p=new i.Deferred();m.props.forEach(function(r){var q=b.clone(r);
q.from=q.to=q.value;q.easing="linear";o.push(q)});var n=k.create({element:m.element,props:o});
this.__rafDraw(n,p);j.push(p.promise())}.bind(this));return i.all(j)},diff:function(k){var j=[];
var o;var m=this.getStyles();var l=k.getStyles();var n;m.forEach(function(u,q){var r=u.element;
var s=u.props;var v={};var t=false;for(var p in l[q]){if(l[q].hasOwnProperty(p)){v[p]=l[q][p]
}}v.props=[];s.forEach(function(y){var w=y.property;var x=k.findStyle(r,w);if(x===null){v.props.push(y)
}else{if(x.value!==y.value||(h(w)&&t===true)){v.props.push(x);if(h(w)){t=true}}}});
if(v.props.length>0){j.push(v)}});return new f("diff",j,this.options)}};d.exports=f
},{"./helper/isTransformProperty":59,"ac-animation-sequencer":4,"ac-object":46}],59:[function(b,d,a){var c=["skew","scale","rotate","translateX","translateY","translateZ"];
d.exports=function(f){return(c.indexOf(f)!==-1)}},{}],60:[function(b,c,a){var g=b("./utils/addEventListener");
var f=b("ac-prefixer");c.exports=function d(k,i,j,h){i=f.getEventType(i);return g(k,i,j,h)
}},{"./utils/addEventListener":71,"ac-prefixer":63}],61:[function(c,d,b){var a=c("./utils/dispatchEvent");
var f=c("ac-prefixer");d.exports=function g(j,i,h){i=f.getEventType(i);return a(j,i,h)
}},{"./utils/dispatchEvent":72,"ac-prefixer":63}],62:[function(b,c,a){c.exports={addEventListener:b("./addEventListener"),dispatchEvent:b("./dispatchEvent"),preventDefault:b("./preventDefault"),removeEventListener:b("./removeEventListener"),stop:b("./stop"),stopPropagation:b("./stopPropagation"),target:b("./target")}
},{"./addEventListener":60,"./dispatchEvent":61,"./preventDefault":66,"./removeEventListener":67,"./stop":68,"./stopPropagation":69,"./target":70}],63:[function(b,c,a){var d=b("./ac-prefixer/Prefixer");
c.exports=new d();c.exports.Prefixer=d},{"./ac-prefixer/Prefixer":64}],64:[function(d,b,g){var k=d("./Prefixer/camelCasedEvents");
var n=/(\([^\)]+\))/gi;var h=/([^ ,;\(]+(\([^\)]+\))?)/gi;var j=/(-webkit-|-moz-|-ms-)|^(webkit|moz|ms)/gi;
var a=/^(webkit|moz|ms)/gi;var f=["-webkit-","-moz-","-ms-"];var l=["Webkit","Moz","ms"];
var m=["webkit","moz","ms"];function c(){this._supportsAvailable=("CSS" in window&&"supports" in window.CSS);
this._cssPrefixes=f;this._domPrefixes=l;this._evtPrefixes=m;this._styleProperties={};
this._styleValues={};this._eventTypes={}}var i=c.prototype;i.getEventType=function(p){var q;
var o;p=p.toLowerCase();if(p in this._eventTypes){return this._eventTypes[p]}if(this._checkEventType("on"+p)){return this._eventTypes[p]=p
}if(k[p]){for(q in k[p]){if(this._checkEventType(q)){return this._eventTypes[p]=k[p][q]
}}}for(o=0;o<this._evtPrefixes.length;o++){if(this._checkEventType("on"+this._evtPrefixes[o]+p)){this._eventTypes[p]=this._evtPrefixes[o]+p;
this._reduceAvailablePrefixes(o);return this._eventTypes[p]}}return this._eventTypes[p]=p
};i._checkEventType=function(o){return(o in window||o in document)};i.getStyleProperty=function(r){var q;
var o;var p;r+="";if(r in this._styleProperties){return this._styleProperties[r].dom
}r=this._toDOM(r);this._prepareTestElement();o=r.charAt(0).toUpperCase()+r.substr(1);
if(r==="filter"){q=["WebkitFilter","filter"]}else{q=(r+" "+this._domPrefixes.join(o+" ")+o).split(" ")
}for(p=0;p<q.length;p++){if(this._el.style[q[p]]!==undefined){if(p!==0){this._reduceAvailablePrefixes(p-1)
}this._memoizeStyleProperty(r,q[p]);return q[p]}}this._memoizeStyleProperty(r,false);
return false};i._memoizeStyleProperty=function(r,o){var p=this._toCSS(r);var q=(o===false)?false:this._toCSS(o);
this._styleProperties[r]=this._styleProperties[o]=this._styleProperties[p]=this._styleProperties[q]={dom:o,css:q}
};i.getStyleCSS=function(q,p){var o;q=this.getStyleProperty(q);if(!q){return false
}o=this._styleProperties[q].css;if(typeof p!=="undefined"){p=this.getStyleValue(q,p);
if(p===false){return false}o+=":"+p+";"}return o};i.getStyleValue=function(q,p){var o;
p+="";q=this.getStyleProperty(q);if(!q){return false}if(this._testStyleValue(q,p)){return p
}o=this._styleProperties[q].css;p=p.replace(h,function(s){var r;var v;var u;var t;
if(s[0]==="#"||!isNaN(s[0])){return s}v=s.replace(n,"");u=o+":"+v;if(u in this._styleValues){if(this._styleValues[u]===false){return""
}return s.replace(v,this._styleValues[u])}r=this._cssPrefixes.map(function(w){return w+s
});r=[s].concat(r);for(t=0;t<r.length;t++){if(this._testStyleValue(q,r[t])){if(t!==0){this._reduceAvailablePrefixes(t-1)
}this._styleValues[u]=r[t].replace(n,"");return r[t]}}this._styleValues[u]=false;
return""}.bind(this));p=p.trim();return(p==="")?false:p};i._testStyleValue=function(q,p){var o;
if(this._supportsAvailable){q=this._styleProperties[q].css;return CSS.supports(q,p)
}this._prepareTestElement();o=this._el.style[q];try{this._el.style[q]=p}catch(r){return false
}return(this._el.style[q]&&this._el.style[q]!==o)};i.stripPrefixes=function(o){o=String.prototype.replace.call(o,j,"");
return o.charAt(0).toLowerCase()+o.slice(1)};i._reduceAvailablePrefixes=function(o){if(this._cssPrefixes.length!==1){this._cssPrefixes=[this._cssPrefixes[o]];
this._domPrefixes=[this._domPrefixes[o]];this._evtPrefixes=[this._evtPrefixes[o]]
}};i._toDOM=function(p){var o;if(p.toLowerCase()==="float"){return"cssFloat"}p=p.replace(/-([a-z])/g,function(r,q){return q.toUpperCase()
});if(p.substr(0,2)==="Ms"){p="ms"+p.substr(2)}return p};i._toCSS=function(p){var o;
if(p.toLowerCase()==="cssfloat"){return"float"}if(a.test(p)){p="-"+p}return p.replace(/([A-Z]+)([A-Z][a-z])/g,"$1-$2").replace(/([a-z\d])([A-Z])/g,"$1-$2").toLowerCase()
};i._prepareTestElement=function(){if(!this._el){this._el=document.createElement("_")
}else{this._el.style.cssText="";this._el.removeAttribute("style")}};b.exports=c
},{"./Prefixer/camelCasedEvents":65}],65:[function(b,c,a){c.exports={transitionend:{onwebkittransitionend:"webkitTransitionEnd",onmstransitionend:"MSTransitionEnd"},animationstart:{onwebkitanimationstart:"webkitAnimationStart",onmsanimationstart:"MSAnimationStart"},animationend:{onwebkitanimationend:"webkitAnimationEnd",onmsanimationend:"MSAnimationEnd"},animationiteration:{onwebkitanimationiteration:"webkitAnimationIteration",onmsanimationiteration:"MSAnimationIteration"},fullscreenchange:{onmsfullscreenchange:"MSFullscreenChange"},fullscreenerror:{onmsfullscreenerror:"MSFullscreenError"}}
},{}],66:[function(c,d,a){d.exports=function b(f){f=f||window.event;if(f.preventDefault){f.preventDefault()
}else{f.returnValue=false}}},{}],67:[function(c,d,b){var a=c("./utils/removeEventListener");
var g=c("ac-prefixer");d.exports=function f(k,i,j,h){i=g.getEventType(i);return a(k,i,j,h)
}},{"./utils/removeEventListener":73,"ac-prefixer":63}],68:[function(d,g,b){var a=d("./stopPropagation");
var c=d("./preventDefault");g.exports=function f(h){h=h||window.event;a(h);c(h);
h.stopped=true;h.returnValue=false}},{"./preventDefault":66,"./stopPropagation":69}],69:[function(c,d,b){d.exports=function a(f){f=f||window.event;
if(f.stopPropagation){f.stopPropagation()}else{f.cancelBubble=true}}},{}],70:[function(b,c,a){c.exports=function d(f){f=f||window.event;
return(typeof f.target!=="undefined")?f.target:f.srcElement}},{}],71:[function(b,c,a){c.exports=function d(i,g,h,f){if(i.addEventListener){i.addEventListener(g,h,!!f)
}else{i.attachEvent("on"+g,h)}return i}},{}],72:[function(b,c,a){c.exports=function d(i,h,g){var f;
if(i.dispatchEvent){if(g){f=new CustomEvent(h,g)}else{f=new CustomEvent(h)}i.dispatchEvent(f)
}else{f=document.createEventObject();if(g&&"detail" in g){f.detail=g.detail}i.fireEvent("on"+h,f)
}return i}},{}],73:[function(b,c,a){c.exports=function d(i,g,h,f){if(i.removeEventListener){i.removeEventListener(g,h,!!f)
}else{i.detachEvent("on"+g,h)}return i}},{}],74:[function(b,c,a){c.exports=b(27)
},{}],75:[function(b,c,a){arguments[4][46][0].apply(a,arguments)},{"./ac-object/clone":76,"./ac-object/create":77,"./ac-object/defaults":78,"./ac-object/extend":79,"./ac-object/getPrototypeOf":80,"./ac-object/isDate":81,"./ac-object/isEmpty":82,"./ac-object/isRegExp":83,"./ac-object/toQueryParameters":84}],76:[function(c,d,b){var h=c("./extend");
var a=Object.prototype.hasOwnProperty;var f=function(i,j){var k;for(k in j){if(a.call(j,k)){if(j[k]===null){i[k]=null
}else{if(typeof j[k]==="object"){i[k]=Array.isArray(j[k])?[]:{};f(i[k],j[k])}else{i[k]=j[k]
}}}}return i};d.exports=function g(j,i){if(i){return f({},j)}return h({},j)}},{"./extend":79}],77:[function(b,c,a){c.exports=b(48)
},{}],78:[function(b,c,a){c.exports=b(49)},{"./extend":79}],79:[function(b,c,a){c.exports=b(31)
},{}],80:[function(b,c,a){c.exports=b(32)},{}],81:[function(b,c,a){c.exports=b(52)
},{}],82:[function(b,c,a){c.exports=b(33)},{}],83:[function(b,c,a){c.exports=b(54)
},{}],84:[function(b,c,a){c.exports=b(34)},{qs:74}],85:[function(b,c,a){a.ScrollView=b("./ac-scrollview/ScrollView");
a.MouseWheel=b("./ac-scrollview/input/MouseWheel");a.ScrollBounds=b("./ac-scrollview/ScrollBounds");
a.Y_AXIS="y";a.X_AXIS="x"},{"./ac-scrollview/ScrollBounds":87,"./ac-scrollview/ScrollView":88,"./ac-scrollview/input/MouseWheel":91}],86:[function(c,d,a){var b=c("ac-object");
function f(g,h){this._parent=g;this._axis=h;this._inputs=[];this._startTouchMove=null;
this._shouldTouchEnd=false;this._checkToPreventDefault=false}f.prototype={_calculateTouchAngles:function(){var n={x:0,y:0};
var i=this._inputs[this._inputs.length-1];var k=this._inputs[0];var g=i.x-k.x;var m=i.y-k.y;
var l=Math.sqrt(g*g+m*m);if(l===0){return false}var j=Math.asin(m/l);var h=Math.acos(g/l);
n.x=j*(180/Math.PI);n.y=h*(180/Math.PI);n.y-=90;return n},inputStart:function(g,j,h,i){this._inputs=[{x:g,y:j}];
this._startTouchMove={x:g,y:j,timeStamp:h,e:i};this._shouldTouchEnd=false;this._checkToPreventDefault=true
},inputMove:function(g,n,j,k){this._inputs[1]={x:g,y:n};var h=45;var i=-h;var m=this._calculateTouchAngles();
var l=m[this._axis];if(l<=h&&l>=i||this._checkToPreventDefault===false){this._shouldTouchEnd=true;
this._checkToPreventDefault=false;if(this._startTouchMove!==null){this._parent.inputStart(this._startTouchMove.x,this._startTouchMove.y,this._startTouchMove.timeStamp,this._startTouchMove.e);
this._startTouchMove=null}k.preventDefault();this._parent.inputMove.apply(this._parent,arguments)
}},inputEnd:function(g,h){if(this._shouldTouchEnd===true){this._checkToPreventDefault=true;
this._parent.inputEnd.apply(this._parent,arguments)}},on:function(){return this._parent.on.apply(this._parent,arguments)
},off:function(){return this._parent.off.apply(this._parent,arguments)},trigger:function(){return this._parent.trigger.apply(this._parent,arguments)
},once:function(){return this._parent.once.apply(this._parent,arguments)}};d.exports=f
},{"ac-object":75}],87:[function(d,f,b){var c=d("ac-object");function a(k,j,h,g){var i={maxPerSwipe:1,axis:"x"};
this.options=c.extend(i,g||{});this._grid=h;this._scrollInertia=k;this._scrollView=this._scrollInertia.getScrollView();
this._runningIndex=j;this._axisString=(this.options.axis==="x")?"left":"top"}a.prototype={calculateTargetIndex:function(){var g=(this._axisString==="left")?this._scrollView.getTouchContainerWidth():this._scrollView.getTouchContainerHeight();
var i=Math.round(this._scrollInertia.calculateFinalInertiaPosition()[this._axisString]/g);
var h=this._runningIndex;var j=(i-h);if(j>0&&i>h+this.options.maxPerSwipe){i=h+this.options.maxPerSwipe
}else{if(j<0&&i<h-this.options.maxPerSwipe){i=h-this.options.maxPerSwipe}}if(j>0&&i>this._grid[this._axisString].length-1){i=this._grid[this._axisString].length-1
}else{if(j<0&&i<0){i=0}}return i},calculateFuturePositions:function(){var g=this.calculateTargetIndex();
return{left:g*this._scrollView.getTouchContainerWidth(),top:g*this._scrollView.getTouchContainerHeight()}
}};f.exports=a},{"ac-object":75}],88:[function(c,b,h){var d=c("ac-object");var n=c("ac-event-emitter").EventEmitter;
var m=c("./TouchInertia");var l=c("./input/MouseWheel");var k=c("./input/Touch");
var j=c("./input/Input");var i=c("./InputPreventDefault");var a=c("./model/Scroll");
var f={startBounceDistance:0,endBounceDistance:0,axis:"y",touch:true,mouseWheel:false,mouse:false,preventDefault:true};
function g(p,o){this.options=d.extend(d.clone(f),o||{});this._element=p;this._touchContainerWidth=(typeof this.options.containerWidth==="number")?this.options.containerWidth:p.offsetWidth;
this._touchContainerHeight=(this.options.containerHeight||p.offsetHeight);this._innerScrollWidth=(this.options.innerWidth||p.offsetWidth)+this.options.startBounceDistance+this.options.endBounceDistance;
this._innerScrollHeight=(this.options.innerHeight||p.offsetHeight)+this.options.startBounceDistance+this.options.endBounceDistance;
this._scroll=new a();this._scrollPositions=[];this._inputNormalize=new j(this._scroll);
this._inputNormalize=new i(this._inputNormalize,this.options.axis);this._inputNormalize.on("input_start",this.inputStart,this);
this._inputNormalize.on("input_move",this.inputMove,this);this._inputNormalize.on("input_end",this.inputEnd,this);
if(this.options.touch===true){this._touch=new k(this._inputNormalize,p);this._touch.bindDOMEvents()
}if(this.options.mouseWheel===true){this._mouseWheel=new l(this._inputNormalize,p);
this._mouseWheel.bindDOMEvents()}}g.prototype={};g.prototype.__playInertia=function(p){var o=p.calculateInertiaPositions();
var q=function(s){var r=o[s];if(r===undefined||this._down===true){return}this._scroll.scrollTo(r.left,r.top);
window.requestAnimationFrame(function(){q(s+1)})}.bind(this);q(0)};g.prototype.getTouchContainerHeight=function(){return this._touchContainerHeight
};g.prototype.getTouchContainerWidth=function(){return this._touchContainerWidth
};g.prototype.setInnerWidth=function(o){this._innerScrollWidth=o;return this};g.prototype.setInnerHeight=function(o){this._innerScrollHeight=o;
return this};g.prototype.getInnerScrollWidth=function(){return this._innerScrollWidth
};g.prototype.getInnerScrollHeight=function(){return this._innerScrollHeight};g.prototype.getScrollYDistance=function(){var o=this.getInnerScrollHeight()-this.getTouchContainerHeight()-(this.options.startBounceDistance+this.options.endBounceDistance);
if(o<0){o=0}return o};g.prototype.getScrollXDistance=function(){var o=this.getInnerScrollWidth()-this.getTouchContainerWidth()-(this.options.startBounceDistance+this.options.endBounceDistance);
if(o<0){o=0}return o};g.prototype.inputStart=function(o,r,q,p){this._down=true;
this.trigger("scrollStart",{originalEvent:p,timeStamp:q})};g.prototype.inputMove=function(p){var o=p.scrollLeft;
var q=p.scrollTop;if(p.originalEvent.type==="mousewheel"){if(q>this.getScrollYDistance()){q=this.getScrollYDistance()
}else{if(q<0){q=0}}if(o>this.getScrollXDistance()){o=this.getScrollXDistance()}else{if(o<0){o=0
}}}this._scrollPositions.push({left:o,top:q,timeStamp:p.timeStamp});this._scroll.scrollTo(o,q)
};g.prototype.inputEnd=function(q){var u=true;var p=this._scrollPositions;var v=[];
var s=this._scrollPositions[this._scrollPositions.length-1];var r=q.timeStamp;if(!s){return
}for(var t=0;t<p.length;t+=1){v[v.length]=p[t].left;v[v.length]=p[t].top;v[v.length]=p[t].timeStamp
}var o=new m(this,{left:this._scroll.scrollLeft,top:this._scroll.scrollTop},v,s.timeStamp,r);
this._down=false;this.trigger("inertiaStart",{originalEvent:q,originalEventName:"touchend",inertia:o,position:{left:this._scroll.scrollLeft,top:this._scroll.scrollTop},velocity:o.calculateVelocity(),preventDefault:function(){u=false
}});if(u===true){this.__playInertia(o)}this._scrollPositions=[]};g.prototype.once=function(){return this._scroll.once.apply(this._scroll,arguments)
};g.prototype.on=function(){return this._scroll.on.apply(this._scroll,arguments)
};g.prototype.off=function(){return this._scroll.off.apply(this._scroll,arguments)
};g.prototype.trigger=function(){return this._scroll.trigger.apply(this._scroll,arguments)
};g.prototype.scrollTo=function(p,o){return this._scroll.scrollTo(p,o)};b.exports=g
},{"./InputPreventDefault":86,"./TouchInertia":89,"./input/Input":90,"./input/MouseWheel":91,"./input/Touch":92,"./model/Scroll":93,"ac-object":75}],89:[function(d,f,b){var c=d("ac-object");
function a(i,l,g,k,h,j){var m={frictionCoefficient:0.95,minFrictionVelocity:0.1};
this.options=c.extend(m,j||{});this._scrollView=i;this._currentPosition=l;this.__scrollLeft=this._currentPosition.left;
this.__scrollTop=this._currentPosition.top;this._positions=g;this._lastTouchMove=k;
this._timeStamp=h;this._frameRate=(1000/60)}a.prototype={__stepThroughFriction:function(m,l){var n=m+this._frictionVelocityX;
var k=l+this._frictionVelocityY;if(Math.abs(this._frictionVelocityX)<=this.options.minFrictionVelocity){n=m
}if(Math.abs(this._frictionVelocityY)<=this.options.minFrictionVelocity){k=l}this._frictionVelocityX*=this.options.frictionCoefficient;
this._frictionVelocityY*=this.options.frictionCoefficient;var h=0;var g=0;var j=0.03;
var i=0.08;if(n<this._minScrollLeft){h=this._minScrollLeft-n}else{if(n>this._maxScrollLeft){h=this._maxScrollLeft-n
}}if(k<this._minScrollTop){g=this._minScrollTop-k}else{if(k>this._maxScrollTop){g=this._maxScrollTop-k
}}if(h!==0){if(h*this._frictionVelocityX<=0){this._frictionVelocityX+=h*j}else{this._frictionVelocityX=h*i
}}if(g!==0){if(g*this._frictionVelocityY<=0){this._frictionVelocityY+=g*j}else{this._frictionVelocityY=g*i
}}return{left:n,top:k}},getScrollView:function(){return this._scrollView},calculateInertiaDuration:function(){var g=this.calculateInertiaPositions();
return g.length*this._frameRate},calculateVelocity:function(){var m=this._positions;
var h=m.length-1;var n=h;for(var l=h;l>0&&m[l]>(this._lastTouchMove-100);l-=3){n=l
}var p=m[h]-m[n];var g=this.__scrollLeft-(m[n-2]);var o=this.__scrollTop-(m[n-1]);
var j=g/p*this._frameRate;var k=o/p*this._frameRate;if((this._timeStamp-this._lastTouchMove)>=100){j=0;
k=0}if(isNaN(j)){j=0}if(isNaN(k)){k=0}return{left:j,top:k}},calculateInertiaPositions:function(){this._minScrollLeft=0;
this._minScrollTop=0;this._maxScrollLeft=this._scrollView.getScrollXDistance();
this._maxScrollTop=this._scrollView.getScrollYDistance();var g=this._positions;
var m=[];var j=this.calculateVelocity();this._frictionVelocityX=j.left;this._frictionVelocityY=j.top;
var l=this.__scrollLeft;var k=this.__scrollTop;var h;var i=0;if(Math.abs(this._frictionVelocityX)<this.options.minFrictionVelocity&&Math.abs(this._frictionVelocityY)<this.options.minFrictionVelocity){h=this.__stepThroughFriction(l,k)
}while((Math.abs(this._frictionVelocityX)>=this.options.minFrictionVelocity||Math.abs(this._frictionVelocityY)>=this.options.minFrictionVelocity)){h=this.__stepThroughFriction(l,k);
l=h.left;k=h.top;m.push(h)}if(l<this._minScrollLeft){l=this._minScrollLeft}else{if(l>this._maxScrollLeft){l=this._maxScrollLeft
}}if(k<this._minScrollTop){k=this._minScrollTop}else{if(k>this._maxScrollTop){k=this._maxScrollTop
}}m[m.length-1]={left:l,top:k};return m},calculateFinalInertiaPosition:function(){var g=this.calculateInertiaPositions();
if(g.length===0){return{left:this.__scrollLeft,top:this.__scrollTop}}return g[g.length-1]
}};f.exports=a},{"ac-object":75}],90:[function(b,c,a){var f=b("ac-event-emitter").EventEmitter;
function g(h){this._startingInputPosition=null;this._lastInputPosition=null;this._inputPositions=[];
this._scroll=h}var d=g.prototype=new f();d.inputStart=function(h,l,j,i){var k={x:h,y:l,timeStamp:j};
this._inputPositions.push(k);this._startingInputPosition=k;this.trigger("input_start",{timeStamp:j,originalEvent:i})
};d.inputMove=function(h,m,k,i){var l={x:h,y:m,timeStamp:k};this._inputPositions.push(l);
this._lastInputPosition=l;var j=this.getScrollValues();this.trigger("input_move",{scrollLeft:j.x,scrollTop:j.y,timeStamp:k,originalEvent:i})
};d.inputEnd=function(i,h){this.trigger("input_end",{lastInputPosition:this._lastInputPosition,inputPositions:this._inputPositions.slice(),timeStamp:i,originalEvent:h});
this._inputPositions=[];this._lastInputPosition=null};d.getScrollValues=function(){var j=this._inputPositions[this._inputPositions.length-2];
var i=(j.x-this._lastInputPosition.x)+this._scroll.scrollLeft;var h=(j.y-this._lastInputPosition.y)+this._scroll.scrollTop;
return{x:i,y:h}};c.exports=g},{}],91:[function(d,f,b){var g=d("ac-dom-events");
var c=d("ac-object");function a(h,i){this._inputController=h;this._element=i;this._scrollTop=0;
this._scrollLeft=0;this._timeout=null;this._hasStarted=false;this._boundMouseWheelComplete=this.mouseWheelComplete.bind(this);
this._lastEvent=null;this._velocities=[]}a.prototype={mouseWheelComplete:function(){this._scrollTop=0;
this._scrollLeft=0;this._hasStarted=false;this._inputController.inputEnd(new Date().getTime(),this._lastEvent);
this._lastEvent=null},onMouseWheel:function(k){var i;var h;var j;if(this._hasStarted===false){this._inputController.inputStart(this._scrollLeft,this._scrollTop,k.timeStamp,k);
this._hasStarted=true}i=this._scrollTop+k.wheelDeltaY;h=this._scrollLeft+k.wheelDeltaX;
this._lastEvent=c.clone(k);this._scrollTop=i;this._scrollLeft=h;this._inputController.inputMove(this._scrollLeft,this._scrollTop,k.timeStamp,k);
window.clearTimeout(this._timeout);this._timeout=window.setTimeout(this._boundMouseWheelComplete,100)
},bindDOMEvents:function(){g.addEventListener(this._element,"mousewheel",this.onMouseWheel.bind(this))
}};f.exports=a},{"ac-dom-events":62,"ac-object":75}],92:[function(c,d,a){var f=c("ac-dom-events");
function b(g,h){this._input=g;this._element=h}b.prototype={bindDOMEvents:function(){var g=this._input;
var h=this._element;f.addEventListener(h,"touchstart",function(i){if(i.touches&&i.touches[0]&&i.touches[0].target&&i.touches[0].target.tagName.match(/input|textarea|select/i)){return
}g.inputStart(i.touches[0].pageX,i.touches[0].pageY,i.timeStamp,i)},false);f.addEventListener(h,"touchmove",function(i){g.inputMove(i.touches[0].pageX,i.touches[0].pageY,i.timeStamp,i)
},false);f.addEventListener(h,"touchend",function(i){g.inputEnd(i.timeStamp,i)},false);
f.addEventListener(h,"touchcancel",function(i){g.inputEnd(i.timeStamp,i)},false)
}};d.exports=b},{"ac-dom-events":62}],93:[function(b,c,a){var f=b("ac-event-emitter").EventEmitter;
function g(){this.scrollLeft=0;this.scrollTop=0}var d=g.prototype=new f();d.scrollTo=function(i,h){if(i===this.scrollLeft&&h===this.scrollTop){return
}this.scrollLeft=i;this.scrollTop=h;this.trigger("scroll",{scrollTop:h,scrollLeft:i})
};c.exports=g},{}],94:[function(b,c,a){c.exports.InlineStyleRenderer=b("./ac-style-renderer/InlineStyleRenderer");
c.exports.LogRenderer=b("./ac-style-renderer/LogRenderer")},{"./ac-style-renderer/InlineStyleRenderer":95,"./ac-style-renderer/LogRenderer":96}],95:[function(d,f,c){var a=(function(){var h,g;
if(a){return}g=document.createElement("div");h=["transform","webkitTransform","MozTransform","msTransform","oTransform"];
h.some(function(i){if(i in g.style){a=i;return true}});return a})();var b={transformFunctions:["none","matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","matrix3d","translate3d","translateZ","scale3d","scaleZ","rotate3d","rotateX","rotateY","rotateZ","perspective"],render:function(i,g){var h=this._parseProps(g);
h.forEach(function(j){i.style[j.prop]=j.value})},_mergeTransformProps:function(g){var h=g.reduce(this._partialPropValue.bind(this),"");
return{prop:a,value:h}},_partialPropValue:function(h,i){var j=this._parseTransformFunction(i.prop);
var g=[h," ",j,"(",i.value,")"].join("");return g},_parseTransformFunction:function(g){return g.replace("transform-","")
},_isTransformFunction:function(g){return this.transformFunctions.indexOf(g)!==-1
},_parseProps:function(l){var k=[];var j=[];var n;var m;var o;for(var h=0,g=l.length;
h<g;h++){o=l[h];n=this._isTransformFunction(o.prop);[].push.call(n?j:k,o)}if(j.length){m=this._mergeTransformProps(j);
k.push(m)}return k}};f.exports=b},{}],96:[function(b,c,a){c.exports={render:function(g,f){var d=(arguments.length<2)?g:f;
console.log(d)}}},{}],97:[function(b,c,a){a.Gallery=b("./ac-gallery/Gallery");a.builder=b("./ac-gallery/builder");
a.MediaSegue=b("./ac-gallery/segue/MediaSegue");a.MediaRenderer=b("./ac-gallery/segue/media/MediaRenderer");
a.AnimationSequenceSegue=b("./ac-gallery/segue/AnimationSequence");a.CSSTransitionSegue=b("./ac-gallery/segue/CSSTransition");
a.FadeInCSSTransition=b("./ac-gallery/segue/FadeInCSSTransition");a.fadeInKeyframesGenerator=b("./ac-gallery/keyframe/fadeInKeyframesGenerator");
a.crossFadeKeyframesGenerator=b("./ac-gallery/keyframe/crossFadeKeyframesGenerator");
a.showHideKeyframesGenerator=b("./ac-gallery/keyframe/showHideKeyframesGenerator");
a.horizontalSliderKeyframesGenerator=b("./ac-gallery/keyframe/horizontalSliderKeyframesGenerator")
},{"./ac-gallery/Gallery":98,"./ac-gallery/builder":99,"./ac-gallery/keyframe/crossFadeKeyframesGenerator":109,"./ac-gallery/keyframe/fadeInKeyframesGenerator":110,"./ac-gallery/keyframe/horizontalSliderKeyframesGenerator":111,"./ac-gallery/keyframe/showHideKeyframesGenerator":112,"./ac-gallery/segue/AnimationSequence":116,"./ac-gallery/segue/CSSTransition":117,"./ac-gallery/segue/FadeInCSSTransition":118,"./ac-gallery/segue/MediaSegue":119,"./ac-gallery/segue/media/MediaRenderer":122}],98:[function(b,a,g){var j=b("ac-deferred").Deferred;
var l=b("ac-event-emitter").EventEmitter;var c=b("ac-base").Object;var f=b("./generator/Timeline");
var k=b("./segue/Segue");var d={transitionDuration:0.4,transitionEasing:"linear",locks:true,endless:false};
function i(q,m){var p;m=m||{};if(!q){throw new TypeError("Could not create gallery, no keyframes were specified")
}this._keyboard=null;p=c.clone(d);this.setOptions(c.extend(p,m),{replace:true});
if(this.options.keyboard){this.setKeyboard(this.options.keyboard)}this._keyframes=q;
this._selected=0;this._locked=false;var o=this.getTransitionDuration();var n=k.create({duration:0});
this._keyframes[0].draw()}var h=i.prototype=new l();h.setOptions=function(n,m){m=m||{};
if(m.replace===true){this.options=n}else{this.options=c.extend(this.options,n)}return this
};h.getSelectedKeyframe=function(){return this._keyframes[this._selected]};h.getSelected=function(){return this.getSelectedKeyframe.apply(this,arguments)
};h.getKeyframes=function(){return this._keyframes};h.getKeyframeIndex=function(m){return this._keyframes.indexOf(m)
};h.addKeyframe=function(n,m){m=m||{};if(typeof m.index!=="number"){this._keyframes.push(n)
}else{this._keyframes.splice(m.index,0,n)}this._trigger("keyframeAdd",{keyframe:n,index:this.getKeyframeIndex(n)},m);
return this};h.removeKeyframe=function(n,m){var o;m=m||{};if(this.getSelected()===n){throw new Error("Could not remove keyframe, it is the current selected Keyframe instance.")
}o=this.getKeyframeIndex(n);this._keyframes.splice(o,1);this._trigger("keyframeRemove",{keyframe:n,index:o},m);
return this};h.containsKeyframe=function(m){return(this._keyframes.indexOf(m)!==-1)
};h.numKeyframes=function(){return this._keyframes.length};h.eachKeyframe=function(n,m){this._keyframes.forEach(function(){n.apply(m,arguments)
});return this};h.getNext=function(){var m=this.getSelectedIndex()+1;var n;if(this.isEndless()===true&&m===this.numKeyframes()){m=0
}n=this._keyframes[m];if(n===undefined){n=null}return n};h.getPrevious=function(){var m=this.getSelectedIndex()-1;
var n;if(this.isEndless()===true&&m<0){m=this.numKeyframes()-1}n=this._keyframes[m];
if(n===undefined){n=null}return n};h.getSelectedIndex=function(){return this._selected
};h.showNext=function(m){var p=new j();var o=this.getNext();var n=p.promise();if(o!==null){n=this.show(o,m)
}else{p.reject()}return n};h.showPrevious=function(m){var p=new j();var n=this.getPrevious();
var o=p.promise();if(n!==null){o=this.show(n,m)}else{p.reject()}return o};h.showFirst=function(m){var n=this.getFirst();
return this.show(n,m)};h.showLast=function(m){return this.show(this.getLast(),m)
};h.getLastIndex=function(){return this._keyframes.length-1};h.getLast=function(){return this._keyframes[this.getLastIndex()]
};h._trigger=function(m,o,n){if(n.silent===true){return}o.target=this;this.trigger(m,o)
};h.getTransitionDuration=function(){return this.options.transitionDuration};h.setTransitionDuration=function(o,n){var m=this.options.transitionDuration;
this.options.transitionDuration=o;this._trigger("transition-duration-change",{previous:m,duration:o},n||{})
};h.setTransitionEasing=function(o,m){var n=this.options.transitionEasing;this.options.transitionEasing=o;
this._trigger("transition-easing-change",{previous:n,easing:o},m||{})};h.toTimeline=function(o,n){var m=new f(this,o,n);
return m.getTimeline()};h.getFirst=function(){return this._keyframes[0]};h.getLocked=function(){return this._locked
};h.isLocked=function(){return this.getLocked()};h.setLocked=function(m){this._locked=m;
return this._locked};h.getEngaged=function(){return this._engaged};h.setEngaged=function(m){this._engaged=m;
return this._engaged};h.isEndless=function(){return this.options.endless};h.show=function(q,o){var t=new j();
var n;var m;var p;var r=k.create({duration:this.options.transitionDuration,easing:this.options.transitionEasing});
var s=t.promise();o=o||{};if(this.options.locks===true&&this.isLocked()===true){t.reject();
return s}this._locked=true;n=this._keyframes[this._selected];if(typeof q==="number"){m=this._keyframes[q]
}else{if(typeof q==="string"){m=this._keyframes.filter(function(u){return(u.id===q)
})[0]}else{m=q}}if(m===null){throw new TypeError('Could not show Keyframe with supplied query. Query "'+q+'" returned no items.')
}else{if(m===n){t.resolve();this._locked=false;return s}}p=c.extend({outgoing:n,incoming:m},o);
this._trigger("willShow",p,o);if(o.useTransition===false){s=s.then(this._afterShow.bind(this,n,m,p,o));
t.resolve();return s}return r.play(n,m).then(this._afterShow.bind(this,n,m,p,o))
};h.hasKeyboard=function(){return this._keyboard!==null};h.getKeyboard=function(){return this._keyboard
};h.setKeyboard=function(m){if(this._keyboard!==null){this._keyboard.removeKeyDown();
this._keyboard.removeKeyUp()}this._keyboard=m;return this};h.keyboardAddKeyDown=function(){this._keyboard.addKeyDown.apply(this._keyboard,arguments);
return this};h.keyboardAddKeyUp=function(){this._keyboard.addKeyUp.apply(this._keyboard,arguments);
return this};h.keyboardRemoveKeyDown=function(){this._keyboard.removeKeyDown.apply(this._keyboard,arguments);
return this};h.keyboardRemoveKeyUp=function(){this._keyboard.removeKeyUp.apply(this._keyboard,arguments);
return this};h.showPrevious=function(m){var p=new j();var n=this.getPrevious();
var o=p.promise();if(n!==null){o=this.show(n,m)}else{p.reject()}return o};h._afterShow=function(o,m,p,n){this._selected=this._keyframes.indexOf(m);
this._locked=false;return this._trigger("didShow",p,n)};a.exports=i},{"./generator/Timeline":102,"./segue/Segue":120,"ac-base":false}],99:[function(j,b,y){var z=j("ac-base").Object;
var x=j("ac-base").Element;var l=j("ac-base").Environment;var s=j("ac-keyboard");
var g=j("ac-keyframe").Keyframe;var k;try{k=j("ac-analytics").observer.Gallery}catch(t){}var p=j("./Gallery");
var d=j("./controller/Trigger");var h=j("./observer/TriggerPainter");var i=j("./observer/PreviousNextTriggerPainter");
var a=j("./observer/ElementTracker");var w=j("./keyboard/defaultMap");var r=j("./keyframe/crossFadeKeyframesGenerator");
var m=j("./keyframe/showHideKeyframesGenerator");var f=j("./touch/builder");var c="Could not create gallery: there are both custom keyframes and keyframe elements specified";
var q="Could not create gallery: there are no keyframes or elements to generate keyframes from";
var o="Could not create gallery: there is no touch element, but requested touches to be turned on";
var v="Could not create gallery: triggerSelector should be a string";var u={locks:true,shouldUseKeyboard:true,keyboardMap:w};
b.exports=function n(J){J=J||{};J=z.extend(z.clone(u),J);var D=J.keyframes||[];
var G=J.keyframeElements||[];var L=J.shouldUseKeyboard||true;var E,K,C,A,H,B,I,F;
if(J.keyframes&&J.keyframeElements){throw new Error(c)}if(!D||D.length===0){if(G.length===0){throw new Error(q)
}else{G=Array.prototype.slice.call(G);if(l.Feature.cssPropertyAvailable("opacity")&&l.Feature.cssPropertyAvailable("transition")){D=r(G)
}else{D=m(G)}}}J.keyboard=J.keyboard||new s.Keyboard();if(J.shouldUseKeyboard!==true){J.keyboard=undefined
}K=new p(D,J);if(K.hasKeyboard()){K.keyboardAddKeyDown(J.keyboardMap,K)}if(x.isElement(J.engagementElement)){B=new a(K,J.engagementElement)
}if(J.triggerSelector){if(typeof J.triggerSelector!=="string"){throw new Error(v)
}else{C=new d({gallery:K,el:J.triggerSelector});A=(J.activeTriggerClassname)?new h(K,J.triggerSelector,J.activeTriggerClassname):new h(K,J.triggerSelector);
K.on("willShow",A._paint,A);if(!K.isEndless()){H=new i(A);K.on("willShow",H._paint,H)
}}}if(J.touch){if(l.Feature.touchAvailable()&&J.touch!==false){if(!x.isElement(J.touchElement)){throw new Error(o)
}else{I=f(J.touchElement,K,J)}}}if(typeof k==="function"){F=new k(K,((typeof J.analytics==="object")?J.analytics:{}))
}E={gallery:K,elementTracker:B,trigger:C,triggerPainter:A,touchController:I,analytics:F};
return E}},{"./Gallery":98,"./controller/Trigger":101,"./keyboard/defaultMap":108,"./keyframe/crossFadeKeyframesGenerator":109,"./keyframe/showHideKeyframesGenerator":112,"./observer/ElementTracker":113,"./observer/PreviousNextTriggerPainter":114,"./observer/TriggerPainter":115,"./touch/builder":125,"ac-base":false,"ac-keyboard":41,"ac-keyframe":56}],100:[function(f,c,i){var g=f("ac-base").Object;
var h=f("ac-scrollview").ScrollView;var l=f("./../touch/TimelineRenderer");var a=f("ac-animation-sequencer").BasicPlayer;
var m=f("ac-animation-sequencer").TweenClip;var j=f("ac-base").EasingFunctions;
var k=f("ac-scrollview").ScrollBounds;var b=f("./../touch/GalleryGrid");function d(p,n,o){var q={axis:"x",scrollVelocity:1};
this._element=p;this.options=g.extend(q,o||{});this._gallery=n;this._axisString=(this.options.axis==="x")?"left":"top";
if(!this._gallery){throw new TypeError('Could not instantiate Touch Controller. "'+this._gallery+'" is not a valid gallery')
}this._player=this.options.player||new a(n.toTimeline(this.options.bounceOutKeyframe,this.options.bounceInKeyframe));
this._player.setCurrentTime(this._gallery.getTransitionDuration());this._inertiaPlayer=null;
this._enRoute=false;this._runningIndex=this._gallery.getSelectedIndex();this._scrollView=this.options.scrollView||this.__buildScrollView();
this._scrollRenderer=this.options.scrollRenderer||this.__buildScrollRenderer();
this._scrollRenderer.render(this._scrollView.scrollLeft);this._gallery.on("didShow",this.onDidShow,this);
this._scrollView.on("scrollStart",this.onScrollStart,this);this._scrollView.on("inertiaStart",this.onInertiaStart,this);
this._scrollView.on("scroll",this.onScroll,this)}d.prototype={__generateEasingFunction:function(n){return function(q,o,p,r){return j.easeOutBack(q,o,p,r,n)
}},__buildScrollView:function(){var p=this._element.offsetWidth/this.options.scrollVelocity;
var n=this._element.offsetHeight/this.options.scrollVelocity;var o=g.extend(g.clone(this.options),{innerWidth:p*this._gallery.numKeyframes(),innerHeight:n*this._gallery.numKeyframes(),startBounceDistance:p,endBounceDistance:p,touchContainerWidth:p,touchContainerHeight:n});
return new h(this._element,o)},__buildScrollRenderer:function(){var n=g.extend(g.clone(this.options),{bounceDuration:this._gallery.getTransitionDuration()});
return new l(this._player,this._scrollView,n)},getAxis:function(){return this.options.axis||"x"
},getScrollView:function(){return this._scrollView},onDidShow:function(){var n=this._gallery.getSelectedIndex();
this._runningIndex=n;this._scrollView.scrollTo(n*this._scrollView.getTouchContainerWidth(),n*this._scrollView.getTouchContainerHeight())
},onScrollStart:function(){if(this._inertiaPlayer&&typeof this._inertiaPlayer.pause==="function"){this._inertiaPlayer.pause()
}this._scrollStartTimeout=window.setTimeout(function(){this._gallery.trigger("touchStart")
}.bind(this),100)},onScroll:function(p){var o=p.scrollLeft;var n=p.scrollTop;this._scrollRenderer.render(o,n);
this._gallery.trigger("scroll",{scrollLeft:o,scrollTop:n})},onInertiaStart:function(v){v.preventDefault();
this._gallery.trigger("touchEnd");var u=v.inertia;var o=new b(this._gallery,this._scrollView);
var p=new k(u,this._runningIndex,o.getGrid(),this.options);var t=u.calculateFinalInertiaPosition();
var r=p.calculateTargetIndex();var x=0.4;var s=p.calculateFuturePositions().left;
var A=3;var n=Math.abs(p.calculateFuturePositions().left-v.position.left);if(n!==0){x*=(Math.abs(n)/this._scrollView.getTouchContainerWidth())
}if((r-this._runningIndex)!==0){x=x/Math.abs(r-this._runningIndex)}var z=(Math.abs(n)/this._scrollView.getTouchContainerWidth());
var q=0;if(x<0.32&&x>0.15){x+=0.2;q=1.4}else{if(x<=0.15){x+=0.3;q=1.7}}if(q<0){q=0
}else{if(q>A){q=A}}var w=Math.abs(v.velocity.top)-3;if(w<0){w=0}else{if(w>A){w=A
}}var y=new m(x,[{property:"scrollLeft",from:v.position.left,to:p.calculateFuturePositions().left,easing:this.__generateEasingFunction(q)},{property:"scrollTop",from:v.position.top,to:p.calculateFuturePositions().top,easing:this.__generateEasingFunction(w)}]);
if(this._inertiaPlayer){this._inertiaPlayer.off("ended")}this._inertiaPlayer=new a(y);
y.on("tween_update",function(B){this._scrollView.scrollTo(B.scrollLeft,B.scrollTop)
},this);this._inertiaPlayer.play();this._inertiaPlayer.on("ended",function(){this._enRoute=false;
this._gallery.show(r,{useTransition:false,interactionEvent:v.originalEvent})},this);
this._runningIndex=r;this._enRoute=true}};c.exports=d},{"./../touch/GalleryGrid":123,"./../touch/TimelineRenderer":124,"ac-animation-sequencer":4,"ac-base":false,"ac-scrollview":85}],101:[function(c,d,b){var f=c("ac-base").Element;
var h=c("ac-base").Event;function a(i){i=i||{};this._el=i.el||"";this._id=i.id||"href";
this._method=i.method||"data-method";this.setGallery(i.gallery)}var g=a.prototype;
g.setGallery=function(i){this._gallery=i;if(this._gallery!==undefined){this._addListener()
}};g.getGallery=function(){return this._gallery};g.setEl=function(i){this._el=i;
this._removeListener();if(this._gallery!==undefined){this._addListener()}};g.getEl=function(){return this._el
};g.destroy=function(){this._removeListener();this.func=function(){}};g._addListener=function(){if(this._el!==""){this.func=this._onClickTrigger.bind(this);
f.addEventDelegate(document,"click",this._el,this.func)}};g._removeListener=function(){if(this.func){f.removeEventDelegate(document,"click",this._el,this.func);
this.func=null}};g._onClickTrigger=function(i){h.stop(i.originalEvent);this._click(i.currentTarget,i.originalEvent)
};g._click=function(j,i){var l={interactionEvent:i};if(j.getAttribute(this._method)){var m=j.getAttribute(this._method);
if(typeof this._gallery[m]==="function"){this._gallery[m].call(this._gallery,l)
}else{throw new Error(m+" is not a valid method to call")}}else{if(j.getAttribute(this._id)){var k=j.getAttribute(this._id).split("#")[1];
if(k!==""){this._gallery.show(k,l)}else{throw new Error("Trigger has no ID or method")
}}else{throw new Error("Trigger has no ID or method")}}};d.exports=a},{"ac-base":false}],102:[function(c,b,g){var i=c("ac-animation-sequencer").Timeline;
var h=c("ac-keyframe").Interpolation;var j=c("./../segue/media/MediaClip");var f=c("ac-animation-sequencer").TimedClip;
var a=c("ac-animation-sequencer").CompositeClip;i.clipTypes.Media=j;function d(k,m,l){this._gallery=k;
this._bounceOutKeyframe=m;this._bounceInKeyframe=l}d.prototype={getGallery:function(){return this._gallery
},getTimeline:function(){var m;var k=[];var o=this._gallery.getKeyframes().slice(0);
if(this._bounceInKeyframe){o.unshift(this._bounceInKeyframe)}if(this._bounceOutKeyframe){o.push(this._bounceOutKeyframe)
}var n=new h();n.setDuration(this._gallery.getTransitionDuration());for(var l=1;
l<o.length;l+=1){n.setStartKeyframe(o[l-1]).setEndKeyframe(o[l]);m=n.getClip();
m=new f(m,{startDelay:(l-1)*this._gallery.getTransitionDuration(),fill:"none"});
k.push(m)}return new a(k)}};b.exports=d},{"./../segue/media/MediaClip":121,"ac-animation-sequencer":4,"ac-keyframe":56}],103:[function(f,g,c){var h=f("./../helper/isTransformProperty");
var b=f("./../helper/camelCaseToHyphen");var a=f("./../helper/canTransitionStyle");
var d={zIndex:true,display:true,visibility:true,position:true};g.exports=function(q,l,n,m){var p=[];
var i=false;var k=n;var o=l;m=(typeof m==="number")?" "+m+"s":"";var j=m;q.forEach(function(r){var s=r.property;
if(d[s]===true){return}var u=(typeof r.easing==="string")?r.easing:n;var v=(typeof r.duration==="number")?r.duration:l;
var t=(typeof r.delay==="number")?" "+r.delay+"s":m;if(!a(s)){return}if(!h(s)){p.push(b(s)+" "+v+"s "+u+t)
}else{o=v;k=u;j=t;i=true}});if(i===true){p.push("-webkit-transform "+l+"s "+k+j)
}return p.join(",")}},{"./../helper/camelCaseToHyphen":104,"./../helper/canTransitionStyle":105,"./../helper/isTransformProperty":106}],104:[function(b,c,a){c.exports=function(d){return d.replace(/([a-z])([A-Z])/g,"$1-$2").toLowerCase()
}},{}],105:[function(b,c,a){var d=["display"];c.exports=function(f){return(d.indexOf(f)===-1)
}},{}],106:[function(b,d,a){var c=["matrix","translate","translateX","translateY","scale","scaleX","scaleY","rotate","skewX","skewY","matrix3d","translate3d","translateZ","scale3d","scaleZ","rotate3d","rotateX","rotateY","rotateZ","perspective"];
d.exports=function(f){return(c.indexOf(f)!==-1)}},{}],107:[function(f,g,a){var d=f("ac-deferred").Deferred;
var c=f("./buildTransitionString");var i=f("ac-style-renderer").InlineStyleRenderer;
var h=f("ac-base").Element;var b=f("ac-base").Object;g.exports=function(n,s,m,p,o){var j=new d();
var k=c(s,m,p,o);var q=[];var l;var r=function(t){if(t.target===n){h.removeVendorPrefixEventListener(n,"transitionEnd",r);
h.setVendorPrefixStyle(n,"transition","none");window.requestAnimationFrame(j.resolve.bind(j))
}};if(k!==""&&m!==0){h.addVendorPrefixEventListener(n,"transitionEnd",r);l=h.getVendorPrefixStyle(n,"transition")+",";
if(!/none/.test(l)&&l!==","){k=l+k}h.setVendorPrefixStyle(n,"transition",k)}else{window.requestAnimationFrame(j.resolve.bind(j))
}s.forEach(function(t){var u=b.clone(t);u.prop=u.property;if(u.units){u.value+=u.units
}q.push(u)});i.render(n,q);return j.promise()}},{"./buildTransitionString":103,"ac-base":false,"ac-style-renderer":94}],108:[function(b,c,a){var d=b("ac-keyboard").keys;
var f={};f[d.ARROW_LEFT]=function(g){g.preventDefault();if(this.getEngaged()){this.showPrevious({interactionEvent:g})
}};f[d.ARROW_RIGHT]=function(g){g.preventDefault();if(this.getEngaged()){this.showNext({interactionEvent:g})
}};c.exports=f},{"ac-keyboard":41}],109:[function(c,d,a){var f=c("ac-keyframe").Keyframe;
var b=c("ac-base").Object;var g={zIndex:1};d.exports=function(j,h){var i=[];h=b.extend(b.clone(g),h||{});
j.forEach(function(k,m){var l=[];j.forEach(function(n,o){l.push({element:n,props:[{property:"opacity",value:(o===m)?1:0},{property:"z-index",value:(o===m)?(h.zIndex+1):h.zIndex}]})
});i.push(new f(k.id,l))});return i}},{"ac-base":false,"ac-keyframe":56}],110:[function(c,d,a){var g=c("ac-keyframe").Keyframe;
var f=c("./../segue/FadeInCSSTransition");var h=c("./../segue/CSSTransition");var b=c("ac-base").Object;
var i={zIndex:1};d.exports=function(l,j){var k=[];j=b.extend(b.clone(i),j||{});
l.forEach(function(m,o){var n=[];l.forEach(function(p,q){n.push({SegueType:f,element:p,props:[{property:"opacity",value:(q===o)?"1":"0"},{property:"zIndex",value:(q===o)?(j.zIndex+1):j.zIndex}]})
});k.push(new g(m.id,n))});return k}},{"./../segue/CSSTransition":117,"./../segue/FadeInCSSTransition":118,"ac-base":false,"ac-keyframe":56}],111:[function(c,d,b){var h=c("ac-base").Environment.Feature;
var f=c("ac-keyframe").Keyframe;var g=c("./../segue/CSSTransition");var a=c("./../segue/AnimationSequence");
d.exports=function(o){var l=(h.cssPropertyAvailable("transform"))?"translateX":"left";
var m=(h.cssPropertyAvailable("transition"))?g:a;var j={keyframes:[],bounceInKeyframe:null,bounceOutKeyframe:null};
var n=o[0].offsetWidth;o.forEach(function(p,r){var q=[];o.forEach(function(s,t){q.push({element:s,SegueType:m,props:[{property:l,value:-(n*r),units:"px"}]})
});j.keyframes.push(new f(p.id,q))});var i=[];o.forEach(function(p,q){i.push({element:p,props:[{property:l,value:n,units:"px"}]})
});j.bounceInKeyframe=new f("bounceIn",i);var k=[];o.forEach(function(p,q){k.push({element:p,props:[{property:l,value:-(n*(o.length)),units:"px"}]})
});j.bounceOutKeyframe=new f("bounceOut",k);return j}},{"./../segue/AnimationSequence":116,"./../segue/CSSTransition":117,"ac-base":false,"ac-keyframe":56}],112:[function(b,a,d){var h=b("ac-keyframe").Keyframe;
var f=b("ac-animation-sequencer").ElementClip;var j=b("ac-animation-sequencer").BaseClip;
var g=b("ac-animation-sequencer").Timeline;var c=b("ac-base").Object;var i=function(){f.apply(this,arguments)
};i.prototype=new j();c.extend(i.prototype,f.prototype);i.prototype.update=function(l){if(this.props.length<1){return
}var k=this.props.map(function(o){var m=o.units;var n=o.to;n=(m?(n+m):n);return{prop:o.property,value:n}
});this._renderer.render(this.el,k)};i.create=function(k){return new i(k)};g.clipTypes.Gallery_ShowHide=i;
a.exports=function(l){var k=[];l.forEach(function(m,o){var n=[];l.forEach(function(p,q){n.push({element:p,clipType:"Gallery_ShowHide",props:[{property:"display",value:(q===o)?"block":"none"}]})
});k.push(new h(m.id,n))});return k}},{"ac-animation-sequencer":4,"ac-base":false,"ac-keyframe":56}],113:[function(b,c,a){var d=b("ac-base").Element;
var f=b("ac-element-tracker");function g(h,i){if(!d.isElement(i)){return}this._gallery=h;
this._elementTracker=f;var j=this._elementTracker.addElement({element:i,inViewThreshold:0.33});
this._gallery.setEngaged(false);j.on("thresholdenter",this._onEnterWithinThreshold,this);
j.on("thresholdexit",this._onExitWithinThreshold,this);this._elementTracker.start();
return this}g.prototype._onEnterWithinThreshold=function(h){this._gallery.setEngaged(true)
};g.prototype._onExitWithinThreshold=function(h){this._gallery.setEngaged(false)
};c.exports=g},{"ac-base":false,"ac-element-tracker":38}],114:[function(c,d,b){var f=c("ac-base").Element;
function a(h){if(h.getGallery()&&h.getGallery().isEndless()){return}this.triggerPainter=h;
var i={incoming:h.getGallery().getSelected()};this._paint(i)}var g=a.prototype;
g._paint=function(j){var m=j.incoming.id;var n=this.triggerPainter;var i=n.getGallery();
var o=n.getTriggerSelector();var l=f.selectAll(o+"[data-method]");var k=f.selectAll(o+'[data-method="showPrevious"]');
var h=f.selectAll(o+'[data-method="showNext"]');if(l){n._unpaintTriggers(l,"disabled");
if(m===i.getFirst().id){n._paintTriggers(k,"disabled")}else{if(m===i.getLast().id){n._paintTriggers(h,"disabled")
}}}};d.exports=a},{"ac-base":false}],115:[function(c,d,b){var f=c("ac-base").Element;
function a(i,j,k){this.setGallery(i);this.setTriggerSelector(j);k=k||"current";
this.setActiveTriggerClassname(k);var h={incoming:this._gallery.getSelected()};
this._paint(h)}var g=a.prototype;g.setGallery=function(h){this._gallery=h};g.getGallery=function(){return this._gallery
};g.setTriggerSelector=function(h){this._triggerSelector=h};g.getTriggerSelector=function(){return this._triggerSelector
};g.setActiveTriggerClassname=function(h){this._activeTriggerClassname=h};g.getActiveTriggerClassname=function(){return this._activeTriggerClassname
};g._paint=function(i){var k=i.incoming.id;var m=this.getTriggerSelector();var h=this.getActiveTriggerClassname();
var j=f.selectAll(m+"."+h);var l=f.selectAll(m+'[href="#'+k+'"]');this._unpaintTriggers(j,h);
this._paintTriggers(l,h)};g._paintTriggers=function(m,l){var k,h,j;for(k=0,h=m.length;
k<h;k+=1){j=m[k];f.addClassName(j,l)}};g._unpaintTriggers=function(m,l){var k,h,j;
for(k=0,h=m.length;k<h;k+=1){j=m[k];f.removeClassName(j,l)}};d.exports=a},{"ac-base":false}],116:[function(d,f,b){var h=d("ac-animation-sequencer").Timeline;
var a=d("ac-animation-sequencer").BasicPlayer;var c=d("ac-deferred").Deferred;var g=d("ac-keyframe").Interpolation;
function i(k,j,l,m){this._from=k;this._to=j;this._duration=l;this._easing=m}i.prototype={animate:function(){var m=new c();
var n=this._easing;var j=new g();j.setDuration(this._duration).setStartKeyframe(this._from).setEndKeyframe(this._to);
var l=j.getClip();var k=new a(l);k.once("ended",m.resolve,m);k.play();return m.promise()
}};i.create=function(j){return new i(j.from,j.to,j.duration,j.easing)};f.exports=i
},{"ac-animation-sequencer":4,"ac-keyframe":56}],117:[function(c,d,b){var g=c("./../helper/playCSSTransition");
var a=c("ac-deferred");function f(h,i,j,k){this._toKeyframe=h;this._fromKeyframe=i;
this._duration=j;this._easing=k}f.prototype={animate:function(){var i=this._duration;
var j=this._easing;var h=this._toKeyframe.getStyles().map(function(k){return g(k.element,k.props,i,j)
});return a.all(h)}};f.create=function(h){return new f(h.to,h.from,h.duration,h.easing)
};d.exports=f},{"./../helper/playCSSTransition":107}],118:[function(c,b,d){var h=c("./../helper/playCSSTransition");
var f=c("ac-deferred");var g=c("ac-keyframe").Keyframe;var a=c("ac-style-renderer").InlineStyleRenderer;
function i(l){var k={prop:l.property,value:l.value,units:l.units};return k}function j(k,l,m,n){this._toKeyframe=k;
this._fromKeyframe=l;this._duration=m;this._easing=n;this._beforeStyles=[];this._afterStyles=[]
}j.prototype={_renderBeforeStyles:function(){this._beforeStyles.forEach(function(k){a.render(k.element,k.props.map(i))
})},_renderAfterStyles:function(){this._afterStyles.forEach(function(k){a.render(k.element,k.props.map(i))
})},_processIncomingStyle:function(o){var m;var q=this._toKeyframe.findStyle(o.element,"zIndex");
var p=this._fromKeyframe;var n=this._beforeStyles;var k=this._afterStyles;var l={element:o.element,props:[]};
o.props.forEach(function(r){if(r.property==="opacity"){m=p.findStyle(o.element,r.property).value;
if(parseFloat(m)<parseFloat(r.value)){l.props.push(r);if(q){n.push({element:o.element,props:[q]})
}}else{k.push({element:o.element,props:[r]});if(q){k[k.length-1].props.push(q)}}}else{l.props.push(r)
}});return l},animate:function(){var m=this._duration;var p=this._easing;var o=this._fromKeyframe;
var n=this._toKeyframe;var l=this._toKeyframe.getStyles().map(this._processIncomingStyle.bind(this));
this._renderBeforeStyles();var k=l.map(function(q){return h(q.element,q.props,m,p)
});return f.all(k).then(this._renderAfterStyles.bind(this))}};j.create=function(k){return new j(k.to,k.from,k.duration,k.easing)
};b.exports=j},{"./../helper/playCSSTransition":107,"ac-keyframe":56,"ac-style-renderer":94}],119:[function(c,d,b){var a=c("ac-deferred");
var f=c("ac-animation-sequencer").Pause;var h=c("ac-animation-sequencer").ReversibleVideo;
function g(k,j,i){this._from=k;this._to=j;this._duration=i}g.prototype={animate:function(){var i=[];
var j=this._duration;var k=this._from;this._to.getStyles().forEach(function(l){l.props.forEach(function(s){var n;
var r;var m;var p;var o;var q;if(s.property==="time"){r=new a.Deferred();p=k.findStyle(l.element,s.property);
o=(p.value<s.value)?1:-1;n=new h(l.element);if(s.value!==0){m=new f(n,[0,s.value]);
m._monitor._init();m.once("pauseenter",function(){m=undefined;r.resolve()})}else{if(s.value===0){q=function(){if(l.element.currentTime===0){r.resolve()
}l.element.removeEventListener("timeupdate",q)};l.element.addEventListener("timeupdate",q)
}else{if(s.value===this.element.duration){q=function(){if(l.element.currentTime===this.element.duration){r.resolve()
}l.element.removeEventListener("timeupdate",q)};l.element.addEventListener("timeupdate",q)
}}}n.playbackRate=(Math.abs(p.value-s.value)/j)*o;n.play();i.push(r.promise())}})
});return a.all(i)}};g.create=function(i){return new g(i.from,i.to,i.duration,i.easing)
};d.exports=g},{"ac-animation-sequencer":4}],120:[function(c,b,d){var a=c("./CSSTransition");
var k=c("./AnimationSequence");var j=c("./../helper/playCSSTransition");var f=c("ac-deferred");
var h=f.Deferred;var g=c("ac-keyframe").Keyframe;function i(l,m){this._duration=l;
this._easing=m||"linear"}i.prototype={_determineSegueType:function(m){var l;if(m.SegueType!==undefined){l=m.SegueType
}else{if(typeof m.clipType!=="undefined"&&m.clipType!=="Element"){l=k}else{l=a}}return l
},_sortPropertiesBySegueType:function(m){var n=[];function l(o){for(var p=0;p<n.length;
p+=1){if(n[p].Type===o){return n[p]}}}m.getStyles().forEach(function(p){var q=this._determineSegueType(p);
var o=l(p.SegueType);if(!o){o={Type:q,properties:[]};n.push(o)}o.properties.push({clipType:p.clipType,element:p.element,props:p.props})
}.bind(this));return n},_transition:function(s,n){var p=[];var l;var m=this._duration;
var o=this._easing;if(this._duration===0){return n.draw()}var q=(m===0)?n.clone():s.diff(n);
var r=this._sortPropertiesBySegueType(q);var t=this._sortPropertiesBySegueType(n.diff(s));
r.forEach(function(w,u){var y=new g("to",w.properties);var x=new g("from",t[u].properties);
var v=w.Type.create({duration:m,easing:o,to:y,from:x});p.push(v.animate())});return f.all(p)
},getDuration:function(){return this._duration},setDuration:function(l){this._duration=l;
return this},getEasing:function(){return this._easing},setEasing:function(l){this._easing=l;
return this},play:function(m,l){return this._transition(m,l)}};i.create=function(l){return new i(l.duration,l.easing,l)
};b.exports=i},{"./../helper/playCSSTransition":107,"./AnimationSequence":116,"./CSSTransition":117,"ac-keyframe":56}],121:[function(f,g,c){var a=f("ac-animation-sequencer").TweenClip;
var i=f("./MediaRenderer");var d=f("ac-base").Object;function b(){a.apply(this,arguments)
}var h=b.prototype=new a();b.create=function(j){j=j||{};if(!j.element){throw new TypeError("MediaClip could not be created: "+j.element+" is not a valid element")
}j.renderer=new i(j.element);return new b(j)};g.exports=b},{"./MediaRenderer":122,"ac-animation-sequencer":4,"ac-base":false}],122:[function(b,c,a){function f(g){this._element=g
}var d=f.prototype;d.render=function(h,g){g.forEach(function(i){if(i.prop==="time"){if(h.currentTime!==i.value){h.currentTime=i.value
}}})};c.exports=f},{}],123:[function(c,d,b){function a(f,g){this._gallery=f;this._scrollView=g
}a.prototype={getGrid:function(){var g={left:[],top:[]};for(var f=0;f<this._gallery.numKeyframes();
f+=1){g.left.push(this._scrollView.getTouchContainerWidth()*f);g.top.push(this._scrollView.getTouchContainerHeight()*f)
}return g}};d.exports=a},{}],124:[function(c,f,a){var b=c("ac-base").Object;var g={axis:"x",bounceDuration:0};
function d(i,j,h){this.options=b.extend(g,h||{});this._player=i;this._touchScrollBounds=j
}d.prototype={_calculateScrollPercentage:function(i,h){return{left:i/this._touchScrollBounds.getScrollXDistance(),top:h/this._touchScrollBounds.getScrollYDistance()}
},calculateCurrentTime:function(k,j){var h=this._calculateScrollPercentage(k,j);
var l=(this.options.axis==="x")?"left":"top";var i=(this._player.getDuration()-(this.options.bounceDuration*2))*h[l];
return this.options.bounceDuration+i},render:function(i,h){this._player.setCurrentTime(this.calculateCurrentTime(i,h));
return this}};f.exports=d},{"ac-base":false}],125:[function(b,c,a){var d=b("ac-base").Element;
var f=b("./../controller/Touch");c.exports=function g(k,i,j){j=j||{};var h=new f(k,i,j);
return h}},{"./../controller/Touch":100,"ac-base":false}],126:[function(d,g,a){var h="ac-storage-";
var c=d("./ac-storage/Item");var i=d("./ac-storage/Storage");var b=d("./ac-storage/Storage/storageAvailable");
var f=new i(h);f.Item=c;f.storageAvailable=b;g.exports=f},{"./ac-storage/Item":127,"./ac-storage/Storage":134,"./ac-storage/Storage/storageAvailable":136}],127:[function(d,b,j){var a=d("ac-base").adler32;
var i=d("ac-base").Object;var k=d("./Item/apis");var c=d("./Item/createExpirationDate");
var l=d("./Item/encoder");var h=1000*60*60*24;var g=30;function f(m){if(!m||typeof m!=="string"){throw"ac-storage/Item: Key for Item must be a string"
}this._key=m;this._checksum=null;this._expirationDate=null;this._metadata=null;
this._value=null;i.synthesize(this);this.setExpirationDate(f.createExpirationDate(g))
}f.prototype={save:function(){var o;var n;var p;var m={};o=k.best(m);if(o){if(this.value()===null&&typeof o.removeItem==="function"){return o.removeItem(this.key())
}else{if(typeof o.setItem==="function"){n=this.__state();p=l.encode(n);return o.setItem(this.key(),p,this.expirationDate())
}}}return false},load:function(){var m;var n;m=k.best();if(m&&typeof m.getItem==="function"){n=m.getItem(this.key());
this.__updateState(l.decode(n));if(n===null||this.hasExpired()){this.remove();return false
}else{return true}}else{return false}},remove:function(){var m;this.__updateState(null);
m=k.best();return m.removeItem(this.key())},hasExpired:function(m){if(((this.expirationDate()!==false)&&(this.expirationDate()<=Date.now()))||!this.__checksumIsValid(m)){return true
}return false},value:function(m){if(this.hasExpired(m)){this.remove()}return this._value
},setChecksum:function(m){if(m===null){this._checksum=m}else{if(typeof m==="string"&&m!==""){this._checksum=a(m)
}else{throw"ac-storage/Item#setChecksum: Checksum must be null or a string"}}},setExpirationDate:function(m){if(m===null){m=f.createExpirationDate(g)
}if(m!==false){if(typeof m==="string"){m=new Date(m).getTime()}if(m&&typeof m.getTime==="function"){m=m.getTime()
}if(!m||isNaN(m)){throw"ac-storage/Item: Invalid date object provided as expirationDate"
}m-=m%h;if(m<=Date.now()){m=false}}this._expirationDate=m},__state:function(){var m={};
m.checksum=this.checksum();m.expirationDate=this.expirationDate();m.metadata=this.metadata();
m.value=this.value();return m},__updateState:function(m){var o;var n;if(m===null){m={checksum:null,expirationDate:null,metadata:null,value:null}
}for(o in m){n="set"+o.charAt(0).toUpperCase()+o.slice(1);if(typeof this[n]==="function"){this[n](m[o])
}}},__checksumIsValid:function(m){if(m){m=a(m);if(!this.checksum()){throw"ac-storage/Item: No checksum exists to determine if this Item’s value is valid. Try loading context from persistent storage first."
}else{if(m===this.checksum()){return true}}return false}else{if(this.checksum()){throw"ac-storage/Item: No checksum passed, but checksum exists in Item’s state."
}}return true},setKey:function(){throw"ac-storage/Item: Cannot set key after synthesizing"
}};f.createExpirationDate=c;b.exports=f},{"./Item/apis":128,"./Item/createExpirationDate":131,"./Item/encoder":132,"ac-base":false}],128:[function(d,g,b){var h=d("ac-base").log;
var c=d("./apis/localStorage");var a=d("./apis/userData");var f={_list:[c,a],list:function(){return this._list
},all:function(k){h("ac-storage/Item/apis.all: Method is deprecated");var i=Array.prototype.slice.call(arguments,1);
if(typeof k!=="string"){throw"ac-storage/Item/apis.all: Method name must be provided as a string"
}var j=this.list().map(function(l){if(l.available()){if(typeof l[k]==="function"){return l[k].apply(l,i)
}else{throw"ac-storage/Item/apis.all: Method not available on api"}}return false
});return j},best:function(){var i=null;this.list().some(function(j){if(j.available()){i=j;
return true}});return i}};g.exports=f},{"./apis/localStorage":129,"./apis/userData":130,"ac-base":false}],129:[function(d,f,b){var a=d("ac-base").Environment.Feature;
var g=window.localStorage;var i=window.sessionStorage;var h;var c={name:"localStorage",available:function(){if(h===undefined){h=a.localStorageAvailable()
}return h},getItem:function(j){return g.getItem(j)||i.getItem(j)},setItem:function(k,l,j){if(j===false){i.setItem(k,l)
}else{g.setItem(k,l)}return true},removeItem:function(j){g.removeItem(j);i.removeItem(j);
return true}};f.exports=c},{"ac-base":false}],130:[function(d,f,c){var g=d("ac-base").Element;
var i=1000*60*60*24;var a="ac-storage";var h;var b={name:"userData",available:function(){if(h===undefined){h=false;
if(document&&document.body){var j=this.element();if(g.isElement(j)&&j.addBehavior!==undefined){h=true
}if(h===false){this.removeElement()}}else{throw"ac-storage/Item/apis/userData: DOM must be ready before using #userData."
}}return h},getItem:function(j){var k=this.element();k.load(a);return k.getAttribute(j)||null
},setItem:function(k,m,j){var l=this.element();l.setAttribute(k,m);if(j===false){j=new Date(Date.now()+i)
}if(j&&typeof j.toUTCString==="function"){l.expires=j.toUTCString()}l.save(a);return true
},removeItem:function(j){var k=this.element();k.removeAttribute(j);k.save(a);return true
},_element:null,element:function(){if(this._element===null){this._element=document.createElement("meta");
this._element.setAttribute("id","userData");this._element.setAttribute("name","ac-storage");
this._element.style.behavior="url('#default#userData')";document.getElementsByTagName("head")[0].appendChild(this._element)
}return this._element},removeElement:function(){if(this._element!==null){g.remove(this._element)
}return this._element}};f.exports=b},{"ac-base":false}],131:[function(b,c,a){var f=1000*60*60*24;
var d=function(h,g){if(typeof h!=="number"){throw"ac-storage/Item/createExpirationDate: days parameter must be a number."
}if(g===undefined||typeof g==="number"){g=g===undefined?new Date():new Date(g)}if(typeof g.toUTCString!=="function"||g.toUTCString()==="Invalid Date"){throw"ac-storage/Item/createExpirationDate: fromDate must be a date object, timestamp, or undefined."
}g.setTime(g.getTime()+(h*f));return g.getTime()};c.exports=d},{}],132:[function(b,c,a){var f=b("./encoder/compressor");
var d={encode:function(i){var g;var h;h=f.compress(i);try{g=JSON.stringify(h)}catch(j){}if(!this.__isValidStateObjString(g)){throw"ac-storage/Item/encoder/encode: state object is invalid or cannot be saved as string"
}return g},decode:function(g){var h;var i;if(!this.__isValidStateObjString(g)){if(g===undefined||g===null||g===""){return null
}throw"ac-storage/Item/encoder/decode: state string does not contain a valid state object"
}try{h=JSON.parse(g)}catch(j){throw"ac-storage/Item/encoder/decode: Item state object could not be decoded"
}i=f.decompress(h);return i},__isValidStateObjString:function(g){try{if(g!==undefined&&g.substring(0,1)==="{"){return true
}return false}catch(h){return false}}};c.exports=d},{"./encoder/compressor":133}],133:[function(b,c,a){var g=1000*60*60*24;
var d=14975;var f={mapping:{key:"k",checksum:"c",expirationDate:"e",metadata:"m",value:"v"},compress:function(j){var h={};
var i=f.mapping;for(var l in i){if(j.hasOwnProperty(l)&&j[l]){if(l==="expirationDate"){var k=this.millisecondsToOffsetDays(j[l]);
h[i[l]]=k}else{h[i[l]]=j[l]}}}return h},decompress:function(h){var k={};var j=f.mapping;
for(var l in j){if(h.hasOwnProperty(j[l])){if(l==="expirationDate"){var i=this.offsetDaysToMilliseconds(h[j[l]]);
k[l]=i}else{k[l]=h[j[l]]}}}return k},millisecondsToOffsetDays:function(h){return Math.floor(h/g)-d
},offsetDaysToMilliseconds:function(h){return(h+d)*g}};c.exports=f},{}],134:[function(g,h,d){var c=g("ac-base").Object;
var f=g("./Item/apis/localStorage");var b=g("./Storage/registry");var a={};function i(k,j){this._namespace=k||"";
this._options=c.extend(c.clone(a),j||{});c.synthesize(this)}i.prototype={getItem:function(j){var k=this.__item(j);
k.load();return k.value()},setItem:function(j,l){var k=this.__item(j);if(l===undefined){throw"ac-storage/Storage#setItem: Must provide value to set key to. Use #removeItem to remove."
}k.setValue(l);return k.save()},removeItem:function(j){var k=this.__item(j);b.remove(k.key(),true);
return k.save()},removeExpired:function(){var p;var n;if(f.available()){for(n=0;
n<window.localStorage.length;n++){p=this.__item(window.localStorage.key(n));if(p.hasExpired()&&JSON.parse(window.localStorage[window.localStorage.key(n)]).v!=="undefined"){p.remove()
}}}else{var l="ac-storage";var o=document.getElementById("userData");o.load(l);
var k;var q=o.xmlDocument;var m=q.firstChild.attributes;var j=m.length;n=-1;while(++n<j){k=m[n];
p=this.__item(k.nodeName);if(p.hasExpired()&&JSON.parse(k.nodeValue).v!=="undefined"){p.remove()
}}}},__item:function(j){if(typeof j!=="string"||j===""){throw"ac-storage/Storage: Key must be a String."
}var k=b.item(this.namespace()+j);return k}};h.exports=i},{"./Item/apis/localStorage":129,"./Storage/registry":135,"ac-base":false}],135:[function(f,g,c){var d=f("../Item");
var b={};var a={item:function(h){var i=b[h];if(!i){i=this.register(h)}return i},register:function(h){var i=b[h];
if(!i){i=new d(h);b[h]=i}return i},clear:function(i){var h;for(h in b){this.remove(h,i)
}return true},remove:function(h,i){var j=b[h];if(j&&!!i){j.remove()}b[h]=null;return true
}};g.exports=a},{"../Item":127}],136:[function(c,f,a){var d=c("../Item/apis");var g;
f.exports=function b(){if(g!==undefined){return g}g=!!d.best();return g}},{"../Item/apis":128}],137:[function(b,c,a){c.exports=b("./ac-promomanager/PromoManager")
},{"./ac-promomanager/PromoManager":138}],138:[function(h,f,j){var c=h("ac-base").Array;
var l=h("ac-base").Class;var a=h("ac-base").Element;var i=h("ac-base").Log;var g=h("ac-base").Object;
var d=h("ac-storage");var b=h("./PromoManager/History");var m=h("./PromoManager/Promo");
var k=new l({__defaultOptions:{prefixString:"pm-",appendLocale:true,rotate:false,rotateInterval:3000,rotateAnimation:true},initialize:function(p,q,o){if(d===undefined){throw"AC.PromoManager requires that AC.Storage exists on page."
}this._options=g.extend(g.clone(this.__defaultOptions),o||{});this._history=null;
this._storageName=null;this._promos=null;this._currentPromo=-1;this._delegate={};
g.synthesize(this);this.setStorageName(p);var n=this.setPromos(q);if(n.length<2){return null
}this.__weightPromos();this.__selectFirstPromo();if(this._options.rotate){window.setInterval(function(){this.selectNextPromo(this._options.rotateAnimation)
}.bind(this),this._options.rotateInterval)}k.instances.push(this)},selectPromo:function(n,o){var p=this.promos();
o=!!o;if(p[n]){if(p[this.currentPromo()]){p[this.currentPromo()].hide(o)}p[n].show(o);
this.setCurrentPromo(n);this.history().add(n)}},selectNextPromo:function(o){var n=this.currentPromo()+1;
if(n>=this.promos().length){n=0}this.selectPromo(n,o)},currentPromoElement:function(){return this.promos()[this.currentPromo()]._promo
},__selectFirstPromo:function(){var n=-1;var p=this.promos();var o=this.history().data();
p.forEach(function(q,r){if((r!==o[0])&&((n===-1)||(q.weight()>p[n].weight()))){n=r
}});this.selectPromo(n,false)},__lowestWeight:function(){var n=1;this.promos().forEach(function(o){var p=o.weight();
if(p<n){n=p}});return n},__weightPromos:function(){var p=[];var n=0;var o=0;this.promos().forEach(function(q){var r=q.weight();
if(typeof r!=="number"||r<=0){p.push(q)}else{n+=r}if(n>1){new i("Promo weighting total is > 100%.")
}});if(p.length>0){o=((1-n)/p.length);p.forEach(function(q){q.setWeight(o)})}this.__loadHistory(this.storageName());
this.__historicallyWeightPromos()},__loadHistory:function(p){var n;var q;if(!this.promos()){throw"Cannot load history until we know how many promos there are."
}n=Math.floor(1/(this.__lowestWeight()||1))-1;q=new b(p,n);var o=q.load();this.setHistory(q);
return o},__historicallyWeightPromos:function(){var p=this.promos();var o=this.history().data();
var n=(1/o.length)*-1;o.forEach(function(q){if(p[q]!==undefined){p[q].offsetWeight(n)
}})},setStorageName:function(n){if(typeof this._storageName==="string"){throw"Storage name cannot change after it is set."
}this._storageName=this.options().prefixString+n;if(this.options().appendLocale===true){this._storageName+="-"+window.document.documentElement.getAttribute("lang")
}return this._storageName},setHistory:function(n){if(n===undefined){throw"Cannot set PromoManager history to undefined."
}if(this._history!==null){throw"Cannot set PromoManager history more than once for the same Promo Slot."
}this._history=n;return this._history},setPromos:function(o){if(this._promos!==null){throw"Cannot set promos more than once for the same Promo Slot."
}var n=this;n._promos=[];o=(typeof o==="string")?a.selectAll("."+o):c.toArray(o);
if(o.length<2){return n._promos}o.forEach(function(p){n._promos.push(m.promoFromElementOrObject(p))
});return n._promos},setCurrentPromo:function(n){if(typeof n==="number"&&this.promos()[n]!==undefined){this._currentPromo=n
}return this._currentPromo}});k.instances=[];f.exports=k},{"./PromoManager/History":139,"./PromoManager/Promo":140,"ac-base":false,"ac-storage":126}],139:[function(d,f,b){var a=d("ac-base").Object;
var c=d("ac-storage");var g=function(j,h,i){this._data=[];a.synthesize(this);this.__key=j;
this.__maxLength=h||1;this.__expiration=i||30};g.prototype={add:function(h){var i=this.data();
i=[h].concat(i);this.setData(i);this.save();return this.data()},save:function(){var j=this.data();
var i=this.__key;var h=this.__expiration;if(typeof i==="string"){c.setItem(i,j,h)
}},load:function(){if(typeof this.__key==="string"){var h=c.getItem(this.__key);
if(h){return this.setData(h)}}},setData:function(h){if(Array.isArray(h)){if(h.length>this.__maxLength){h=h.slice(0,this.__maxLength)
}this._data=h}return this._data}};f.exports=g},{"ac-base":false,"ac-storage":126}],140:[function(f,c,h){var b=f("ac-base").EasingFunctions;
var a=f("ac-base").Element;var j=f("ac-base").Environment;var k=f("ac-base").Function;
var d=f("ac-base").Object;var g=f("ac-base").String;var i=function(m,n,l){if(!a.isElement(m)){throw"AC.PromoManager.Promo require Element Node as first argument."
}this._options=d.extend(d.clone(this.__defaultOptions),l||{});this._promo=m;this._weight=0;
d.synthesize(this);this.setWeight(n||0);if(this.options().hideOnInit===true){this.hide()
}};i.prototype={__defaultOptions:{hideOnInit:true,animationDuration:0.4,animationTimingFunction:"ease-out",animationZIndex:1000},offsetWeight:function(l){if(!isNaN(l)){this.setWeight(this.weight()+l)
}return this.weight()},show:function(l){if(!l){a.setStyle(this.promo(),{display:"block"})
}else{this.__animate(1)}},hide:function(l){if(!l){a.setStyle(this.promo(),{display:"none"})
}else{this.__animate(0)}},__animate:function(m){var l=this.promo();var p=a.getStyle(l,"z-index")||"auto";
var n=this.options().animationZIndex;var o=function(){a.setStyle(l,{"z-index":p});
if(m===0){a.setStyle(l,{display:"none"})}};if(m>0){a.setStyle(l,{display:"block"})
}a.setStyle(l,{"z-index":n});if(j.Feature.cssPropertyAvailable("transition")){this.__animateWithCSS(m,o)
}else{this.__animateWithJS(m,o)}},__animateWithCSS:function(m,o){var l=this.promo();
var n;a.setVendorPrefixStyle(l,"transition","opacity "+this.options().animationDuration+"s "+this.options().animationTimingFunction);
a.setStyle(l,{opacity:0});n=function(p){if(p.target===l&&p.propertyName==="opacity"){o();
a.removeVendorPrefixEventListener(l,"transitionEnd",n)}};a.addVendorPrefixEventListener(l,"transitionEnd",n)
},__animateWithJS:function(n,q){var m=this.promo();var p=g.toCamelCase(this.options().animationTimingFunction);
var o;if((p==="easeOut")||(p==="easein")||(p==="easeinOut")){p+="Quad"}o=b[p];var l=function(r){if(n===0){r=(1-r)
}if(typeof o==="function"){r=o(r,0,1,1)}a.setStyle(m,{opacity:r})};k.iterateFramesOverAnimationDuration(l,this.options().animationDuration,q)
},setWeight:function(l){if(!isNaN(l)){this._weight=l}return this._weight}};i.promoFromElementOrObject=function(l){if(a.isElement(l)){return i.promoFromElement(l)
}else{return i.promoFromObject(l)}};i.promoFromElement=function(m){if(!a.isElement(m)){throw"Promo is not an element."
}var l=new i(m);return l};i.promoFromObject=function(m){if(m===undefined||!a.isElement(m.promo)){throw"Promo object not formatted as expected."
}var l=new i(m.promo,m.weight);return l};c.exports=i},{"ac-base":false}],141:[function(b,c,a){c.exports.SlideShow=b("./ac-slideshow/SlideShow")
},{"./ac-slideshow/SlideShow":142}],142:[function(f,g,c){var d=f("ac-base").Object;
var b={autoplay:true,pauseOnUserInteraction:true,initialDelay:1000,delayBetweenSlides:3000};
var h;function a(i,j){this.gallery=i;this.animationTimeout=null;this.options=j||{};
this.currentTime=this.currentTime();this._playing=false;this._progress=0;var k;
k=d.clone(b);this.setOptions(d.extend(k,this.options),{replace:true});if(this.options.autoplay===true){setTimeout(function(){this.play()
}.bind(this),this.options.initialDelay)}if(this.options.pauseOnUserInteraction===true){this.gallery.on("willShow",function(l){if(l.interactionEvent!==this){this.pause()
}},this)}}h=a.prototype;h.setOptions=function(j,i){i=i||{};if(i.replace===true){this.options=j
}else{this.options=d.extend(this.options,j)}return this};h.play=function(){this.animationTimeout=setInterval(function(){this.gallery.showNext({interactionEvent:this});
this._progress+=1}.bind(this),this.options.delayBetweenSlides);this._playing=true
};h.pause=function(){clearTimeout(this.animationTimeout);this._playing=false};h.currentTime=function(){return this.options.initialDelay+(this._progress*(this.options.delayBetweenSlides+(this.options.transitionDuration*1000)))
};g.exports=a},{"ac-base":false}],143:[function(b,c,a){c.exports={adler32:b("./ac-checksum/adler32")}
},{"./ac-checksum/adler32":144}],144:[function(b,c,a){c.exports=function d(h){var f=65521;
var k=1;var g=0;var l;var j;for(j=0;j<h.length;j+=1){l=h.charCodeAt(j);k=(k+l)%f;
g=(g+k)%f}return(g<<16)|k}},{}],145:[function(b,c,a){c.exports={log:b("./ac-console/log")}
},{"./ac-console/log":146}],146:[function(d,f,b){var a="f7c9180f-5c45-47b4-8de4-428015f096c0";
var c=!!(function(){try{return window.localStorage.getItem(a)}catch(h){}}());f.exports=function g(h){if(window.console&&typeof console.log!=="undefined"&&c){console.log(h)
}}},{}],147:[function(d,f,c){var b=d("./ac-dom-nodes/helpers/nodeTypes");var g;
var a={createDocumentFragment:d("./ac-dom-nodes/createDocumentFragment"),filterByNodeType:d("./ac-dom-nodes/filterByNodeType"),insertAfter:d("./ac-dom-nodes/insertAfter"),insertBefore:d("./ac-dom-nodes/insertBefore"),insertFirstChild:d("./ac-dom-nodes/insertFirstChild"),insertLastChild:d("./ac-dom-nodes/insertLastChild"),isComment:d("./ac-dom-nodes/isComment"),isDocument:d("./ac-dom-nodes/isDocument"),isDocumentFragment:d("./ac-dom-nodes/isDocumentFragment"),isDocumentType:d("./ac-dom-nodes/isDocumentType"),isElement:d("./ac-dom-nodes/isElement"),isNode:d("./ac-dom-nodes/isNode"),isNodeList:d("./ac-dom-nodes/isNodeList"),isTextNode:d("./ac-dom-nodes/isTextNode"),remove:d("./ac-dom-nodes/remove"),replace:d("./ac-dom-nodes/replace")};
for(g in b){a[g]=b[g]}f.exports=a},{"./ac-dom-nodes/createDocumentFragment":148,"./ac-dom-nodes/filterByNodeType":149,"./ac-dom-nodes/helpers/nodeTypes":151,"./ac-dom-nodes/insertAfter":153,"./ac-dom-nodes/insertBefore":154,"./ac-dom-nodes/insertFirstChild":155,"./ac-dom-nodes/insertLastChild":156,"./ac-dom-nodes/isComment":157,"./ac-dom-nodes/isDocument":158,"./ac-dom-nodes/isDocumentFragment":159,"./ac-dom-nodes/isDocumentType":160,"./ac-dom-nodes/isElement":161,"./ac-dom-nodes/isNode":162,"./ac-dom-nodes/isNodeList":163,"./ac-dom-nodes/isTextNode":164,"./ac-dom-nodes/remove":165,"./ac-dom-nodes/replace":166}],148:[function(c,d,b){d.exports=function a(g){var f=document.createDocumentFragment();
var h;if(g){h=document.createElement("div");h.innerHTML=g;while(h.firstChild){f.appendChild(h.firstChild)
}}return f}},{}],149:[function(d,f,c){var g=d("./helpers/isNodeType");var a=d("./helpers/nodeTypes").ELEMENT_NODE;
f.exports=function b(i,h){h=h||a;i=Array.prototype.slice.call(i);return i.filter(function(j){return g(j,h)
})}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],150:[function(b,c,a){var d=b("../isNode");
c.exports=function f(h,g){if(!d(h)){return false}if(typeof g==="number"){return(h.nodeType===g)
}return(g.indexOf(h.nodeType)!==-1)}},{"../isNode":162}],151:[function(b,c,a){c.exports={ELEMENT_NODE:1,TEXT_NODE:3,COMMENT_NODE:8,DOCUMENT_NODE:9,DOCUMENT_TYPE_NODE:10,DOCUMENT_FRAGMENT_NODE:11}
},{}],152:[function(f,c,h){var g=f("./nodeTypes");var b=f("./isNodeType");var j=[g.ELEMENT_NODE,g.TEXT_NODE,g.COMMENT_NODE,g.DOCUMENT_FRAGMENT_NODE];
var d=" must be an Element, TextNode, Comment, or Document Fragment";var m=[g.ELEMENT_NODE,g.TEXT_NODE,g.COMMENT_NODE];
var i=" must be an Element, TextNode, or Comment";var k=[g.ELEMENT_NODE,g.DOCUMENT_FRAGMENT_NODE];
var l=" must be an Element, or Document Fragment";var a=" must have a parentNode";
c.exports={parentNode:function(n,q,p,o){o=o||"target";if((n||q)&&!b(n,k)){throw new TypeError(p+": "+o+l)
}},childNode:function(n,q,p,o){o=o||"target";if(!n&&!q){return}if(!b(n,m)){throw new TypeError(p+": "+o+i)
}},insertNode:function(n,q,p,o){o=o||"node";if(!n&&!q){return}if(!b(n,j)){throw new TypeError(p+": "+o+d)
}},hasParentNode:function(n,p,o){o=o||"target";if(!n.parentNode){throw new TypeError(p+": "+o+a)
}}}},{"./isNodeType":150,"./nodeTypes":151}],153:[function(b,c,a){var f=b("./helpers/validate");
c.exports=function d(g,h){f.insertNode(g,true,"insertAfter");f.childNode(h,true,"insertAfter");
f.hasParentNode(h,"insertAfter");if(!h.nextSibling){return h.parentNode.appendChild(g)
}return h.parentNode.insertBefore(g,h.nextSibling)}},{"./helpers/validate":152}],154:[function(c,d,a){var f=c("./helpers/validate");
d.exports=function b(g,h){f.insertNode(g,true,"insertBefore");f.childNode(h,true,"insertBefore");
f.hasParentNode(h,"insertBefore");return h.parentNode.insertBefore(g,h)}},{"./helpers/validate":152}],155:[function(c,d,b){var f=c("./helpers/validate");
d.exports=function a(g,h){f.insertNode(g,true,"insertFirstChild");f.parentNode(h,true,"insertFirstChild");
if(!h.firstChild){return h.appendChild(g)}return h.insertBefore(g,h.firstChild)
}},{"./helpers/validate":152}],156:[function(b,c,a){var d=b("./helpers/validate");
c.exports=function f(g,h){d.insertNode(g,true,"insertLastChild");d.parentNode(h,true,"insertLastChild");
return h.appendChild(g)}},{"./helpers/validate":152}],157:[function(c,d,a){var g=c("./helpers/isNodeType");
var f=c("./helpers/nodeTypes").COMMENT_NODE;d.exports=function b(h){return g(h,f)
}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],158:[function(c,d,b){var g=c("./helpers/isNodeType");
var a=c("./helpers/nodeTypes").DOCUMENT_NODE;d.exports=function f(h){return g(h,a)
}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],159:[function(c,d,b){var g=c("./helpers/isNodeType");
var a=c("./helpers/nodeTypes").DOCUMENT_FRAGMENT_NODE;d.exports=function f(h){return g(h,a)
}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],160:[function(b,c,a){var g=b("./helpers/isNodeType");
var f=b("./helpers/nodeTypes").DOCUMENT_TYPE_NODE;c.exports=function d(h){return g(h,f)
}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],161:[function(c,d,b){var g=c("./helpers/isNodeType");
var a=c("./helpers/nodeTypes").ELEMENT_NODE;d.exports=function f(h){return g(h,a)
}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],162:[function(b,c,a){c.exports=function d(f){return !!(f&&f.nodeType)
}},{}],163:[function(c,d,b){var f=/^\[object (HTMLCollection|NodeList|Object)\]$/;
d.exports=function a(g){if(!g){return false}if(typeof g.length!=="number"){return false
}if(typeof g[0]==="object"&&(!g[0]||!g[0].nodeType)){return false}return f.test(Object.prototype.toString.call(g))
}},{}],164:[function(c,d,a){var g=c("./helpers/isNodeType");var b=c("./helpers/nodeTypes").TEXT_NODE;
d.exports=function f(h){return g(h,b)}},{"./helpers/isNodeType":150,"./helpers/nodeTypes":151}],165:[function(c,d,b){var f=c("./helpers/validate");
d.exports=function a(g){f.childNode(g,true,"remove");if(!g.parentNode){return g
}return g.parentNode.removeChild(g)}},{"./helpers/validate":152}],166:[function(b,d,a){var f=b("./helpers/validate");
d.exports=function c(g,h){f.insertNode(g,true,"insertFirstChild","newNode");f.childNode(h,true,"insertFirstChild","oldNode");
f.hasParentNode(h,"insertFirstChild","oldNode");return h.parentNode.replaceChild(g,h)
}},{"./helpers/validate":152}],167:[function(b,c,a){c.exports=b(27)},{}],168:[function(b,c,a){c.exports=b(46)
},{"./ac-object/clone":169,"./ac-object/create":170,"./ac-object/defaults":171,"./ac-object/extend":172,"./ac-object/getPrototypeOf":173,"./ac-object/isDate":174,"./ac-object/isEmpty":175,"./ac-object/isRegExp":176,"./ac-object/toQueryParameters":177}],169:[function(b,c,a){c.exports=b(29)
},{"./extend":172}],170:[function(b,c,a){c.exports=b(48)},{}],171:[function(b,c,a){c.exports=b(49)
},{"./extend":172}],172:[function(b,c,a){c.exports=b(31)},{}],173:[function(b,c,a){c.exports=b(32)
},{}],174:[function(b,c,a){c.exports=b(52)},{}],175:[function(b,c,a){c.exports=b(33)
},{}],176:[function(b,c,a){c.exports=b(54)},{}],177:[function(b,c,a){c.exports=b(34)
},{qs:167}],178:[function(b,c,a){arguments[4][126][0].apply(a,arguments)},{"./ac-storage/Item":179,"./ac-storage/Storage":186,"./ac-storage/Storage/storageAvailable":188}],179:[function(d,b,j){var a=d("ac-checksum").adler32;
var i=d("ac-object");var k=d("./Item/apis");var c=d("./Item/createExpirationDate");
var l=d("./Item/encoder");var h=1000*60*60*24;var g=30;function f(m){if(!m||typeof m!=="string"){throw"ac-storage/Item: Key for Item must be a string"
}this._key=m;this._checksum=null;this._expirationDate=null;this._metadata=null;
this._value=null;this.setExpirationDate(f.createExpirationDate(g))}f.prototype={save:function(){var o;
var n;var p;var m={};o=k.best(m);if(o){if(this.value()===null&&typeof o.removeItem==="function"){return o.removeItem(this.key())
}else{if(typeof o.setItem==="function"){n=this.__state();p=l.encode(n);return o.setItem(this.key(),p,this.expirationDate())
}}}return false},load:function(){var m;var n;m=k.best();if(m&&typeof m.getItem==="function"){n=m.getItem(this.key());
this.__updateState(l.decode(n));if(n===null||this.hasExpired()){this.remove();return false
}else{return true}}else{return false}},remove:function(){var m;this.__updateState(null);
m=k.best();return m.removeItem(this.key())},hasExpired:function(m){if(((this.expirationDate()!==false)&&(this.expirationDate()<=Date.now()))||!this.__checksumIsValid(m)){return true
}return false},value:function(m){if(this.hasExpired(m)){this.remove()}return this._value
},setValue:function(m){this._value=m},setChecksum:function(m){if(m===null){this._checksum=m
}else{if(typeof m==="string"&&m!==""){this._checksum=a(m)}else{throw"ac-storage/Item#setChecksum: Checksum must be null or a string"
}}},checksum:function(){return this._checksum},setExpirationDate:function(m){if(m===null){m=f.createExpirationDate(g)
}if(m!==false){if(typeof m==="string"){m=new Date(m).getTime()}if(m&&typeof m.getTime==="function"){m=m.getTime()
}if(!m||isNaN(m)){throw"ac-storage/Item: Invalid date object provided as expirationDate"
}m-=m%h;if(m<=Date.now()){m=false}}this._expirationDate=m},expirationDate:function(){return this._expirationDate
},__state:function(){var m={};m.checksum=this.checksum();m.expirationDate=this.expirationDate();
m.metadata=this.metadata();m.value=this.value();return m},__updateState:function(m){var o;
var n;if(m===null){m={checksum:null,expirationDate:null,metadata:null,value:null}
}for(o in m){n="set"+o.charAt(0).toUpperCase()+o.slice(1);if(typeof this[n]==="function"){this[n](m[o])
}}},__checksumIsValid:function(m){if(m){m=a(m);if(!this.checksum()){throw"ac-storage/Item: No checksum exists to determine if this Item’s value is valid. Try loading context from persistent storage first."
}else{if(m===this.checksum()){return true}}return false}else{if(this.checksum()){throw"ac-storage/Item: No checksum passed, but checksum exists in Item’s state."
}}return true},setKey:function(){throw"ac-storage/Item: Cannot set key /after/ initialization!"
},key:function(){return this._key},metadata:function(){return this._metadata},setMetadata:function(m){this._metadata=m
}};f.createExpirationDate=c;b.exports=f},{"./Item/apis":180,"./Item/createExpirationDate":183,"./Item/encoder":184,"ac-checksum":143,"ac-object":168}],180:[function(d,g,b){var h=d("ac-console").log;
var c=d("./apis/localStorage");var a=d("./apis/userData");var f={_list:[c,a],list:function(){return this._list
},all:function(k){h("ac-storage/Item/apis.all: Method is deprecated");var i=Array.prototype.slice.call(arguments,1);
if(typeof k!=="string"){throw"ac-storage/Item/apis.all: Method name must be provided as a string"
}var j=this.list().map(function(l){if(l.available()){if(typeof l[k]==="function"){return l[k].apply(l,i)
}else{throw"ac-storage/Item/apis.all: Method not available on api"}}return false
});return j},best:function(){var i=null;this.list().some(function(j){if(j.available()){i=j;
return true}});return i}};g.exports=f},{"./apis/localStorage":181,"./apis/userData":182,"ac-console":145}],181:[function(d,f,b){var a=d("ac-feature");
var g=window.localStorage;var i=window.sessionStorage;var h;var c={name:"localStorage",available:function(){try{localStorage.setItem("localStorage",1);
localStorage.removeItem("localStorage")}catch(j){return false}if(h===undefined){h=a.localStorageAvailable()
}return h},getItem:function(j){return g.getItem(j)||i.getItem(j)},setItem:function(k,l,j){if(j===false){i.setItem(k,l)
}else{g.setItem(k,l)}return true},removeItem:function(j){g.removeItem(j);i.removeItem(j);
return true}};f.exports=c},{"ac-feature":1}],182:[function(d,f,c){var g=d("ac-dom-nodes");
var i=1000*60*60*24;var a="ac-storage";var h;var b={name:"userData",available:function(){if(h===undefined){h=false;
if(document&&document.body){var j=this.element();if(g.isElement(j)&&j.addBehavior!==undefined){h=true
}if(h===false){this.removeElement()}}else{throw"ac-storage/Item/apis/userData: DOM must be ready before using #userData."
}}return h},getItem:function(j){var k=this.element();k.load(a);return k.getAttribute(j)||null
},setItem:function(k,m,j){var l=this.element();l.setAttribute(k,m);if(j===false){j=new Date(Date.now()+i)
}if(j&&typeof j.toUTCString==="function"){l.expires=j.toUTCString()}l.save(a);return true
},removeItem:function(j){var k=this.element();k.removeAttribute(j);k.save(a);return true
},_element:null,element:function(){if(this._element===null){this._element=document.createElement("meta");
this._element.setAttribute("id","userData");this._element.setAttribute("name","ac-storage");
this._element.style.behavior="url('#default#userData')";document.getElementsByTagName("head")[0].appendChild(this._element)
}return this._element},removeElement:function(){if(this._element!==null){g.remove(this._element)
}return this._element}};f.exports=b},{"ac-dom-nodes":147}],183:[function(b,c,a){c.exports=b(131)
},{}],184:[function(b,c,a){c.exports=b(132)},{"./encoder/compressor":185}],185:[function(b,c,a){c.exports=b(133)
},{}],186:[function(g,h,d){var c=g("ac-object");var f=g("./Item/apis/localStorage");
var b=g("./Storage/registry");var a={};function i(k,j){this._namespace=k||"";this._options=c.extend(c.clone(a),j||{})
}i.prototype={getItem:function(j){var k=this.__item(j);k.load();return k.value()
},setItem:function(j,l){var k=this.__item(j);if(l===undefined){throw"ac-storage/Storage#setItem: Must provide value to set key to. Use #removeItem to remove."
}k.setValue(l);return k.save()},removeItem:function(j){var k=this.__item(j);b.remove(k.key(),true);
return k.save()},removeExpired:function(){var p;var n;if(f.available()){for(n=0;
n<window.localStorage.length;n++){p=this.__item(window.localStorage.key(n));if(p.hasExpired()&&JSON.parse(window.localStorage[window.localStorage.key(n)]).v!=="undefined"){p.remove()
}}}else{var l="ac-storage";var o=document.getElementById("userData");o.load(l);
var k;var q=o.xmlDocument;var m=q.firstChild.attributes;var j=m.length;n=-1;while(++n<j){k=m[n];
p=this.__item(k.nodeName);if(p.hasExpired()&&JSON.parse(k.nodeValue).v!=="undefined"){p.remove()
}}}},__item:function(j){if(typeof j!=="string"||j===""){throw"ac-storage/Storage: Key must be a String."
}var k=b.item(this.namespace()+j);return k},namespace:function(){return this._namespace
},setNamespace:function(j){this._namespace=j},options:function(){return this._namespace
},setOptions:function(j){this._namespace=j}};h.exports=i},{"./Item/apis/localStorage":181,"./Storage/registry":187,"ac-object":168}],187:[function(b,c,a){arguments[4][135][0].apply(a,arguments)
},{"../Item":179}],188:[function(c,f,a){var d=c("../Item/apis");var g;f.exports=function b(){if(g!==undefined){return g
}g=!!d.best();return g}},{"../Item/apis":180}],189:[function(b,c,a){c.exports=b(25)
},{"./ac-dom-emitter/DOMEmitter":190}],190:[function(b,c,a){c.exports=b(26)},{}],191:[function(b,c,a){c.exports=b(35)
},{"./window-delegate/WindowDelegate":192,"./window-delegate/windowEmitter":193}],192:[function(b,c,a){c.exports=b(36)
},{"./windowEmitter":193}],193:[function(b,c,a){c.exports=b(37)},{"ac-dom-emitter":189}],194:[function(d,g,c){var i=d("ac-base").Element;
var f=d("ac-storage");var b=f.storageAvailable;f.storageAvailable=function(){var j=true;
if(typeof localStorage==="object"){try{localStorage.setItem("localStorage",1);localStorage.removeItem("localStorage")
}catch(k){Storage.prototype._setItem=Storage.prototype.setItem;j=false}}if(j){return b()
}};function a(k,m,l,j){if(f.storageAvailable()){this.element=i.getElementById(k);
this.prefix=m;this.count=l;this.key=j;this._last=f.getItem(this.key);if(this._last){this.next();
this.store()}else{this._last=1;this.store()}}}var h=a.prototype={};h.next=function(){if(f.storageAvailable()){var j=(this._last||0)+1;
if(j>this.count){j=1}if(this._last){i.removeClassName(this.element,this.prefix+1);
i.removeClassName(this.element,this.prefix+this._last);i.addClassName(this.element,this.prefix+j)
}this._last=j;this.store()}};h.store=function(){if(f.storageAvailable()){f.setItem(this.key,this._last)
}};g.exports=a},{"ac-base":false,"ac-storage":178}],195:[function(b,c,a){b("./globalNavDataClickShim.js");
var h=b("ac-base").Element;var f=b("ac-analytics");function d(){var j=document.getElementById("promos");
var i=h.selectAll("ul li a",j);i.forEach(function(k){k.setAttribute("data-analytics-click","prefix:p")
})}function g(p){var n;var j;var k;var m;var o="analytics-promo-id";var l={data:{eVar44:window.innerHeight,eVar43:"{PLATFORM}"}};
d();new f.observer.Page(l);new f.observer.Click();new f.observer.Link()}c.exports=g
},{"./globalNavDataClickShim.js":196,"ac-base":false}],196:[function(b,c,a){var d=b("ac-base").Element;
c.exports=(function(){var g=document.getElementById("globalheader");var h=d.selectAll("a",g);
var f;h.forEach(function(j,i){if(i>0){f="prefix:t,prop3:"+j.innerText||j.textContent;
j.setAttribute("data-analytics-click",f.trim())}})}())},{"ac-base":false}],197:[function(d,c,G){var B=d("ac-base").Element;
var o=d("ac-gallery");var t=d("ac-base").Object;var b=d("ac-base").Viewport;var j=d("../shared/debounce");
var y=d("ac-slideshow").SlideShow;var x=d("window-delegate").WindowDelegate;var J=o.builder;
var C=o.horizontalSliderKeyframesGenerator;var D=o.fadeInKeyframesGenerator;var m=o.showHideKeyframesGenerator;
var L="#";var r=".";var F=".gallery-content";var g="-trigger";var a="ease";var h="fade";
var w="slide";var K="show";var z="large";var u="medium";var I="xsmall";var p={};
var H={galleryType:w,contentClass:F,triggerClass:g,transitionEasing:a,transitionDuration:0.7,touch:true,keyboard:true,endless:true,slideshow:false,autoplay:true,pauseOnUserInteraction:false,initialDelay:4000,delayBetweenSlides:4000};
var v=true;function i(N,M){M=M||{};M=t.extend(t.clone(H),M);M.galleryID=f(N);M.wrapperID=L+M.galleryID;
M.galleryElement=B.select(M.wrapperID);if(!M.galleryElement){return}if(p[M.galleryID]){return p[M.galleryID]
}M.triggerClass=s(M.triggerClass,M.galleryID);M.keyframeEls=q(M.wrapperID,M.contentClass);
if(!M.keyframes){M.keyframes=n(M.keyframeEls,M.galleryType)}x.on("resize orientationchange",function(O){var P=p[M.galleryID].slideShow;
if(P){v=P._playing;if(v){P.pause()}}k(M)});return p[M.galleryID]=E(M)}function E(N){var O,M;
if(!N.keyframes){return}switch(N.galleryType){case h:case K:O={engagementElement:N.galleryElement,touchElement:N.galleryElement,triggerSelector:N.triggerClass,transitionDuration:N.transitionDuration,transitionEasing:N.transitionEasing,endless:N.endless,keyframes:N.keyframes,shouldUseKeyboard:N.keyboard};
break;default:O={engagementElement:N.galleryElement,touchElement:N.galleryElement,triggerSelector:N.triggerClass,transitionDuration:N.transitionDuration,transitionEasing:N.transitionEasing,endless:N.endless,keyframes:N.keyframes.keyframes,bounceInKeyframe:N.keyframes.bounceInKeyframe,bounceOutKeyframe:N.keyframes.bounceOutKeyframe,shouldUseKeyboard:N.keyboard,touch:N.touch};
break}M=J(O);if(N.slideshow){M.slideShow=new y(M.gallery,{autoplay:N.autoplay,pauseOnUserInteraction:N.pauseOnUserInteraction,initialDelay:N.initialDelay,delayBetweenSlides:N.delayBetweenSlides})
}return M}function k(V){var S,W,R,O,Q,T,M=p[V.galleryID];if(v){M.slideShow.pause();
M.slideShow.play()}S=V.keyframes=n(V.keyframeEls,V.galleryType);if(!M){M=E(V);if(!M){return
}}if(M.gallery.getLocked()){M.gallery.once("didShow",function(){k(V)});return}M.gallery.setEngaged(!!S);
if(V.galleryType===w&&!!S){O=M.gallery._keyframes.length;Q=S.keyframes.length;R=M.gallery.getSelectedIndex();
T=Math.floor(R/(O/Q));M.gallery._keyframes[0].draw(0);M.gallery._keyframes=S.keyframes;
S.keyframes[T].draw();M.triggerPainter._paint({incoming:S.keyframes[T]});if(M.touchController){var U=M.gallery.toTimeline(S.bounceOutKeyframe,S.bounceInKeyframe);
var N=V.galleryElement.offsetWidth/M.touchController.options.scrollVelocity;var P=V.galleryElement.offsetHeight/M.touchController.options.scrollVelocity;
M.touchController._scrollView._touchContainerWidth=N;M.touchController._scrollView._touchContainerHeight=P;
M.touchController._scrollView._innerScrollWidth=(N*M.gallery.numKeyframes())+(M.touchController._scrollView.options.startBounceDistance+M.touchController._scrollView.options.endBounceDistance);
M.touchController._scrollView._innerScrollHeight=(P*M.gallery.numKeyframes())+(M.touchController._scrollView.options.startBounceDistance+M.touchController._scrollView.options.endBounceDistance);
M.touchController._player=U;M.touchController._scrollRenderer._player=U;M.touchController.onDidShow()
}M.gallery.show(T,{useTransition:false})}}function f(M){if(M){M=M.match(/^(#)?(\S+)$/);
if(M&&M.length===3){return M[2]}}return M}function l(M){if(M){M=M.match(/^(\.)?(\S+)$/);
if(M&&M.length===3){return r+M[2]}}return F}function s(N,M){if(N&&N!==g){N=N.match(/^(\.)?(\S+)$/);
if(N&&N.length===3){return r+N[2]}}return r+M+g}function A(){var M=b.dimensions().width;
if(M>=1024){return z}else{if(M<=767){return I}else{return u}}}function n(O,Q){var N=A();
var M=O[N];var P;var Q;switch(Q){case h:P=Q=D;break;case K:P=Q=m;break;default:P=Q=C;
break}if(!!M.length){return P(O[N])}else{return null}}function q(Q,N){N=l(N);var S=Q+" "+N+"-";
var O=B.selectAll(S+z);var M=B.selectAll(S+u);var R=B.selectAll(S+I);var P=B.selectAll(Q+" "+N);
if(!O.length&&!!P.length){O=P}if(!M.length&&!!P.length){M=P}if(!R.length&&!!P.length){R=P
}return{large:O,medium:M,xsmall:R}}c.exports={create:i,getSize:A,regenerateGallery:k}
},{"../shared/debounce":200,"ac-base":false,"ac-gallery":97,"ac-slideshow":141,"window-delegate":191}],198:[function(b,a,f){var g=b("ac-base").Element;
var c=b("ac-promomanager");var l=b("./analytics/builder");var h=b("./galleryFactory");
var d=b("./positionSlides");var k=b("ac-analytics");var m=b("window-delegate").WindowDelegate;
var j=b("./ClassNameSwap");var i=(function(){return{initialize:function(){var q=document.getElementById("hero-gallery");
var o=g.selectAll(".gallery-content",q);var t=window.location.href.match(/slide=([0-9]+)/);
var u=document.getElementById("gallery-content-watch");if(u){var x=new j(u,"home-watch-content",3,"home-applewatch-hero");
var n=navigator.userAgent.match(/\(KHTML,\slike\sGecko\) Version\/(\d+\.\d+)/);
var p=/\slike\sMac\sOS\sX\)/.test(navigator.userAgent);if(n&&n[1]&&!p){var v=parseInt(n[1].split("."));
if(v<6||v>100){g.addClassName(document.getElementById("gallery-content-watch"),"is-old-safari")
}}}var r=document.getElementById("promo-macbook-split");if(r){var w=new j(document.getElementById("promo-macbook-split"),"promo-tile-1-version-",2,"home-promotile-one-swap")
}if(t){t=parseInt(t[1],10);if(o[t]){g.setStyle(o[t],"z-index:4")}}else{var y=h.create("hero-gallery",{slideshow:true,autoplay:!/autoplay=false/.test(window.location.href),pauseOnUserInteraction:true,initialDelay:0,delayBetweenSlides:5000}).gallery;
var s="current-"+g.selectAll("#hero-gallery section.gallery-content")[0].id.split("allery-content-")[1];
g.addClassName(q,s);y.on("willShow",function(z){if(s){g.removeClassName(q,s)}if(z.incoming){s=z.incoming.id.replace("gallery-content-","current-");
g.addClassName(q,s)}});d(y,10)}new k.observer.Page();new k.observer.Click();new k.observer.Link();
return this}}}());a.exports=i.initialize()},{"./ClassNameSwap":194,"./analytics/builder":195,"./galleryFactory":197,"./positionSlides":199,"ac-base":false,"ac-promomanager":137,"window-delegate":191}],199:[function(c,b,f){var g=c("ac-base").Element;
var h=c("../shared/debounce");var j=c("window-delegate").WindowDelegate;var i=false;
var k;var a=function(p,o,q){var m;var n;var l=0;k=p;if(o&&o.length){m=o.length;
for(n=0;n<m;n++){if(i){o[n].style.marginLeft=l+"px"}else{o[n].style.left=l+"px"
}o[n].style.borderRightWidth=q+"px";l+=g.getBoundingBox(o[n]).width}}};b.exports=function d(l,o){var n=l.options.engagementElement;
var m=n.getElementsByTagName("section");if(g.hasClassName(document.documentElement,"oldie")){i=true
}a(n,m,o);j.on("resize orientationchange",function(){if(!l.isLocked()){a(n,m,o)
}else{l.once("didShow",function(){a(n,m,o)})}})}},{"../shared/debounce":200,"ac-base":false,"window-delegate":191}],200:[function(c,d,b){d.exports=function a(g,i,f){var h;
return function(){f=f||this;var l=arguments;var k=function(){h=null;g.apply(f,l)
};var j=!h;clearTimeout(h);h=setTimeout(k,i);if(j){g.apply(f,l)}}}},{}]},{},[198]);