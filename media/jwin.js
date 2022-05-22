//  jwin Popup Library 1.17a - Please don't erase this copyright notice.
//  Copyright Jason Anderson 2001-2002. All rights reserved.
//  http://www.jwinlib.com/
//  http://groups.yahoo.com/group/jwin

//contains 2 modifications for SoftChalk LessonBuilder, 10-29-2005

var SIMPLE = 1, CAPTION = 2, LEFT = 1, CENTER = 2, RIGHT = 3, ABOVE = 1, BELOW = 2, DELAY_OPEN = 1, DELAY_CLOSE = 2, JWIN_DEF_FONT = "Verdana,Arial,Helvetica", JWIN_OBJECT = 'jw'

function jw_scr(){}
jc = jw_scr.prototype
jc.m_X = jc.m_Y = jc.o_X = jc.o_Y = jc.o_W = jc.o_H = 0
jc.mouseout = false

function jwin(){}
jwin.version = '1.17a 08/22/2002'
jwin.ns4mouseout = false
jwin.popups = new Array
jwin.popupscount = 0
jwin.popupindexes = new Array
jwin.popupszindex = 1234
jwin.inmodalstate = jwin.modalclosed = false

var jwp = jwin.prototype
jwp.popup = new Object
jwp.show = jw_show
jwp.hide = jw_hide
jwp.kill = jw_closestick
jwp.modalclosed = false
var jw = new jwin()

function jw_show(d,p,t){
     if(jwin.inmodalstate) return
     if(jw_playingevents(d)) return

     var x, y, l = 0, write = true, args = jw_show.arguments, argArr = new Array, tp
     var al = args.length, jh

     if(al > 1){
          if(typeof p == 'object'){
               if(!p.length && (typeof t == 'string' && al == 3)){
                    tp = jw_parsetable(t,p)
               }else{
                    if(al > 3 && !p.length && typeof args[2] == 'number'){
                         for(var j = 2; j < al; j++)
                              argArr[l++] = args[j]
                         tp = jw_parseIt(p,argArr)
                    }else if(p.length){
                         for(j = 0; j < p.length; j++){
                              if(j%2==0){
                                   if(typeof p[j] == 'string')
                                        p[j] = eval(p[j].toUpperCase())
                              }
                         }
                         tp = jw_parseIt(null,p)
                         if(al > 2 && typeof t == 'number'){
                              for(var j = 2; j < al; j++)
                                   argArr[l++] = args[j]
                              tp = jw_parseIt(tp, argArr)
                         }else if(al > 2 && typeof t == 'string'){
                              tp = jw_parsetable(t,tp)
                         }
                    }else if(typeof t == 'object'){
                         for(j = 0; j <t.length; j++){
                              if(j%2==0){
                                   if(typeof t[j] == 'string')
                                        t[j] = eval(t[j].toUpperCase())
                              }
                         }
                         tp = jw_parseIt(p,t)
                         if(al > 3 && typeof args[3] == 'number'){
                              for(var j = 3; j < al; j++)
                                   argArr[l++] = args[j]
                              tp = jw_parseIt(tp, argArr)
                         }else if(al > 3 && typeof args[3] == 'string'){
                              tp = jw_parsetable(args[3],tp)
                         }
                    }else{
                         tp = jw_parseIt(p, argArr)
                    }
               }
          }else{
               if(typeof p == 'string' && al == 2){
                    tp = jw_parsetable(p)
               }else{
                    if(al > 1){
                         for(var j = 1; j < al; j++)
                              argArr[l++] = args[j]
                         tp = jw_parseIt(null, argArr)
                    }
               }
          }
     }

     if(tp == false || typeof tp == 'undefined')
          this.popup = new cls_jwinpopup()
     else
          this.popup = tp


     if(this.popup.Function)
          this.popup.text = jw_callFunction(this.popup.Function)

     // added parenthesis for clarity
     if((this.popup.text == '' && this.popup.captiontext == '') || al == 1)
          write = false

     /**
       * Peter's bug fix,
       * it wasn't detecting the number 0
       */
     if((isNumber(this.popup.text) || isNumber(this.popup.captiontext)) && al != 1)
          write = true

     this.popup.id = d
     this.popup.jwError = jwin.modalclosed = false

     var i = jwin.popupindexes[d] = jwin.popupscount
     jwin.popupscount++
     jwin.popups[i] = this.popup
     jwin.popups[d] = this.popup

     this.window = eval(jwin.popups[d].targetframe) || window
     jwin.popups[d].layref = jw_getlyrbyid(d, this.window.document)

     if(jwin.popups[d].layref == null || jwin.popups[d].layref==false){
          jw_errorhandler()
          return
     }

     if((jh = jwin.popups[d].handicap) && typeof jh == 'string' || (jh = jwin.popups[d].dropshadow) && typeof jh == 'string'){
          if(nav.opera){
               jh = ''
          }else{
               jh = jw_getlyrbyid(jh, this.window.document)
               if(jh == null || jh == false){
                    if(jwin.popups[d].handicap)
                         alert("jwinError: Handicap layer " + jwin.popups[d].handicap + " not found!\nAccessibility feature can't be employed.")
                    else if(jwin.popups[d].dropshadow)
                         alert("jwinError: Drop-shadow layer " + jwin.popups[d].droshadow + " not found!\nDrop Shadow feature can't be employed.")

                    jh = ''
               }
          }
          if(jwin.popups[d].handicap != ''){
               jwin.popups[d].handicap = jh
               jwin.popups[d].handicap.styref = jwin.popups[d].handicap.style || jwin.popups[d].handicap
          }else{
               jwin.popups[d].dropshadow = jh
               jwin.popups[d].dropshadow.styref = jwin.popups[d].dropshadow.style || jwin.popups[d].dropshadow
          }

     }

     var l = jwin.popups[d].layref

     if(jwin.popups[d].capturemouseevents){
          l.mouseOverAction = null
          l.mouseOutAction = null

          if(l.captureEvents)
               l.captureEvents(Event.MOUSEDOWN|Event.MOUSEMOVE|Event.MOUSEUP|Event.MOUSEOVER|Event.MOUSEOUT)

          l.onmouseover = _div_onmouseover
          l.onmouseout = _div_onmouseout

          jw_setmousevent(l,"MOUSEOVER",jw_divonmouseover)
          jw_setmousevent(l,"MOUSEOUT",jw_divonmouseout)
     }

     jwin.popups[d].styref = jwin.popups[d].layref.style || jwin.popups[d].layref

     var jp = jwin.popups[d]

     if(document.styleSheets){
          x = parseInt(jw_getlyrcssproperty("left",d))
          y = parseInt(jw_getlyrcssproperty("top",d))
     }else{
          x = parseInt(jp.styref.left)
          y = parseInt(jp.styref.top)
     }

     jw_loadbgpic(jp.background,d)

     this.x = jp.x = (x || x == 0) ? x : l.offsetLeft
     this.y = jp.y = (y || y == 0) ? y : l.offsetTop

     if(jp.divclass || jp.textclass || jp.captionclass || jp.closeclass)
          jp.classes = true

     if(write)
          jw_write(d)
     else
          jw_setwh(d)

     if(jp.markername){
          if(!jw_setmarker(d))
               return
     }

     if(jp.debug && typeof jw_displayProperties != 'undefined')
          jw_displayProperties(jp)


     if(jp.snapx != '' || jp.snapy !='')
          jp.followmouse=true

     jw_move(d)

     if(jp.modal)
          jwin.inmodalstate = true

     if(jp.autozindex)
          jw_setz(d,jwin.popupszindex++)
     else
          jw_setz(d,'')

     if(jp.visible){
          if(jp.delayinterval > 0 && jp.delayevent == DELAY_OPEN && jp.jwEvt_DelayOpenCloseID == 0)
               jp.jwEvt_DelayOpenCloseID = setTimeout('jw_showme("' + d + '")', jp.delayinterval)
          else
               jw_showme(d)
    }

     if(jp.setstatus)
          return true

}


// Peter's
function isNumber(a) {
    return typeof a == 'number' && isFinite(a);
}


function jw_write(l){
      var tp = jwin.popups[l]

      if(tp.height == '' && tp.autoheight == false || tp.autoheight == true){
           tp.autoheight = true
           tp.height = ''
      }
      if(tp.width == '' && tp.autowidth == false || tp.autowidth == true){
           tp.autowidth = true
           tp.width = ''
      }


      if(tp.captiontext || tp.closetext || tp.closeimage || tp.captionicon){
           tp.code=tp.getCaption()
      }

      /**
       * Peter's bug fix,
       * it wasn't detecting the number 0
       */
      else if (isNumber(tp.captiontext) || isNumber(tp.closetext)) {
      	tp.code=tp.getCaption()
      }
      else if(tp.style == CAPTION){
           tp.captiontext = 'Default captiontext'
           tp.code=tp.getCaption()
      }else if(tp.style==SIMPLE){
           tp.code=tp.getSimple()
      }
      jw_writeme('',l)
}


function jw_writeme(istr,l){
     var tp = jwin.popups[l]
     var ostr = istr || tp.code
     if(document.layers){
          tp.layref.document.open()
          tp.layref.document.write(ostr)
          tp.layref.document.close()
     }else{
          tp.layref.innerHTML = ostr
     }

     if(tp.handicap)
          jw_clipbackdrop(l)

     jw_setwh(l)

     if(tp.dropshadow)
          jw_getdropshadow(l)
}

function jw_setwh(l){
     var tp = jwin.popups[l]
     if(tp.height=='')
          if(nav.opera)
               tp.height = tp.styref.pixelHeight
          else
               tp.height = (tp.layref.clip) ? tp.layref.clip.height : tp.layref.offsetHeight
     if(tp.width=='')
          if(nav.opera)
               tp.width = tp.styref.pixelWidth
          else
               tp.width = (tp.layref.clip) ? tp.layref.clip.width : tp.layref.offsetWidth
}


function isjwin(d){
     if(typeof d == 'number'){
          return !(jwin.popups[jwin.popups[d].id] == null)
     }else{
          if(jwin.popups[d] == null)
               return false

          return !(typeof jwin.popups[d] == 'undefined')
     }

}


function jw_setmousevent(l,a,f){
     eval('switch(a){'+
          'case "MOUSEOVER": l.mouseOverAction = f; break;'+
          'case "MOUSEOUT":  l.mouseOutAction = f;  break;'+
          '}')
}


function _div_onmouseover(e){
     if(nav.ns4){
          if(e.target != this){
               routeEvent(e)
               return
          }
     }else if(nav.ie4up){
          if(window.event.srcElement == this && window.event.srcElement.tagName == "DIV")
               window.event.cancelBubble = true
          else if(window.event.srcElement == this)
               return
     }
     if(this.mouseOverAction)
          this.mouseOverAction(e, this.id)
}


function _div_onmouseout(e){
     if(nav.ns4){
          if(e.target != this){
               routeEvent(e)
               return
          }
     }else if(nav.ie4up){
          if(window.event.srcElement == this && window.event.srcElement.tagName == "DIV")
               window.event.cancelBubble = true
          else if(window.event.srcElement == this)
               return
     }
     if(this.mouseOutAction)
          this.mouseOutAction(e, this.id)
}


function jw_divonmouseover(e,o){
     if(!isjwin(o))
          return

     var jp = jwin.popups[o]

     if(nav.ns4 && !jwin.ns4mouseout){
          if(jp.jwEvt_DelayOpenCloseID > 0){
               clearTimeout(jp.jwEvt_DelayOpenCloseID)
               jp.jwEvt_DelayOpenCloseID = setTimeout('jw_hideme("'+o+'")', jp.delayinterval)
          }
     }else{
          jp.mouseover = true
     }

     if(jp.styref.zIndex != jwin.popupszindex - 1){
          jwin.ns4mouseout = false
          jw_setz(o, jwin.popupszindex++)
     }else{
          jwin.ns4mouseout = true
     }
}


function jw_divonmouseout(e,o){
    if(!isjwin(o))
         return
    jwin.popups[o].mouseover = false
}


function jw_showme(l){
     var jp = jwin.popups[l]
     jp.styref.visibility = "visible"
     jp.isvisible = true

     if(jp.handicap || jp.dropshadow){
          var jh = (jp.handicap) ? jp.handicap : jp.dropshadow
          jh = (jw_ns ? jh : jh.style)
          jh.zIndex = jp.styref.zIndex - 1
          jh.visibility = 'visible'
     }
}


function jw_hide(l){
     if(!isjwin(l))
          return
     if(jwin.inmodalstate && jwin.modalclosed)
          jwin.inmodalstate = jwin.modalclosed = jwin.popups[l].modal = false
     else if(jwin.inmodalstate && jwin.modalclosed == false)
          return

     var jp = jwin.popups[l]

     if(jp == null)
          return

     if(jp.playingtextarray && jp.arrayclose)
          return
     if(jp.playingcaptionarray && jp.arrayclose)
          return

     jp.playingtextarray = jp.playingcaptionarray = false
     jp._textarrlen = jp._captionarrlen = 0
     jp.writetext = ''

     if(!jp.stickaround || jp.delayinterval>0){
          if(jp.delayinterval > 0 && jp.delayevent == DELAY_CLOSE && jp.isvisible)
               jp.jwEvt_DelayOpenCloseID = setTimeout('jw_hideme("' + l + '")', jp.delayinterval)
          else
               jw_hideme(l)
     }
}


function jw_hideme(l){
     if(!isjwin(l))
          return

     var jp = jwin.popups[l]

     if(jp == null)
          return

     if(jp.jwError)
          return

     if(jwin.ns4mouseout || !nav.ns4){
          if(jp.mouseover){
               jp.jwEvt_MouseOverID = setTimeout('jw_hideme("'+l+'")', 1)
               return
          }
     }

     jp.styref.visibility = "hidden"
     jp.isvisible = false

     if(jp.handicap || jp.dropshadow){
          var jh = (jp.handicap) ? jp.handicap : jp.dropshadow
          jh = (jw_ns ? jh : jh.style)
          jh.visibility = 'hidden'
     }


     jw_clearevents(l)
     jp.targetframe.status = ''

     if(jp.classes){
          jp.classes = false
          if(!jw_ns && jp.layref.className)
               jp.layref.className = ''
     }

     if(jp.delpopup)
          jw_delpopup(l)
}

function jw_delpopup(l){
      var pops = new Array, k=0
      if(!jw_ns && jwin.popups[l].divclass)
            jwin.popups[l].layref.className = ''

      if(jwin.popupscount){
            for(var j = 0; j < jwin.popups.length; j++){
                  if(jwin.popups[j].id == l){
                        jwin.popups[l] = null
                        continue
                  }

                  pops[k++] = jwin.popups[j]
                  jwin.popups[j] = null
            }
            jwin.popups.length = 0

            for(j=0; j<pops.length; j++)
                  jwin.popups[j] = pops[j]

            jwin.popupscount = jwin.popups.length
      }
}

function jw_setz(l,z){
     z = z || jwin.popups[l].styref.zIndex
     jwin.popups[l].styref.zIndex = jwin.popups[l].z = z
}


function jw_move(l){
     l = l || jw.popup.id
     var jX = parseInt(jw_scr.m_X), jY = parseInt(jw_scr.m_Y), jp = jwin.popups[l]

     if(isNaN(jX) || isNaN(jY)){
         jX=0; jY=0
         jw_setmousemove()
     }

     jw_setposition(jX,jY,l)

     if(nav.opera){
          jp.styref.pixelLeft = parseInt(jp.x)
          jp.styref.pixelTop =  parseInt(jp.y)
     }else{
          jp.styref.left = parseInt(jp.x) + jpx
          jp.styref.top = parseInt(jp.y) + jpx

          if(jp.handicap || jp.dropshadow){
               var jh = (jp.handicap) ? jp.handicap : jp.dropshadow
               jh = (jw_ns ? jh : jh.style)
               jh.left = (jp.handicap) ? jp.styref.left : ((parseInt(jp.styref.left) + parseInt(jp.dropshadowx)) + jw_nsPixel() + jpx)
               jh.top = (jp.handicap) ? jp.styref.top : ((parseInt(jp.styref.top) + parseInt(jp.dropshadowy)) + jw_nsPixel() + jpx)
          }
     }

}


function jw_clearevents(l){
     if(isjwin(l)){
          var jp = jwin.popups[l]

          clearTimeout(jp.jwEvt_DelayOpenCloseID)
          jp.jwEvt_DelayOpenCloseID = 0

          clearTimeout(jp.jwEvt_PlayArrayID)
          jp.jwEvt_PlayArrayID = 0
     }
}


function jw_playingevents(l){
     if(isjwin(l)){
         if(jw_isdelayeffect(l))
              return true
         if(jw_isplayingtextarray(l))
              return true
     }
     return false
}


function jw_loadbgpic(p,l){
     var jp = jwin.popups[l]

     if(p == ""){
          if(!nav.ns4)
               jp.styref.backgroundImage = "none"
     }else{
          if(nav.ns4)
               jp.layref.background.src = p
          else
               jp.styref.backgroundImage = "url("+p+")"
     }
}


function jw_getlyrcssproperty(p,l){
	if(jwin.popups[l].styref[p])
           return jwin.popups[l].styref[p]
      else
           return jw_getcssproperty("#" + l, p)
}


function jw_getcssproperty(l,p){
     var s = document.styleSheets, r, j, u, c
     for(j = 0; j < s.length; j++){
          r = s[j].cssRules || s[j].rules
          for(u = 0; u < r.length; u++){
               if(r[u].selectorText == l && r[u].style[p])
                    c = r[u].style[p]
          }
     }
     return c
}


function jw_getlyrbyid(l, d){
     var r = "", j
     d = (d || document)
     if(d.getElementById){
          return d.getElementById(l)
     }else if(d.all){
          return d.all[l]
     }else if(d.layers && d.layers.length > 0){
          if(d.layers[l])
               return d.layers[l]

          for(j = 0; j < d.layers.length; j++){
               r = jw_getlyrbyid(l, d.layers[j].document)
               if(r)
                    return r
          }
     }
     return false
}


function jw_getimgbyname(l, d){
     var r = null, j
     d = (d || document)
     if(d.images[l]){
          return d.images[l]
     }else if(d.layers && d.layers.length > 0){
          for(j = 0; j < d.layers.length; j++){
               r = jw_getimgbyname(l, d.layers[j].document)
               if(r && r.length > 0)
                    return r
               else if(r)
                    return [r, d.layers[j]]
          }
     }
     return null
}

function jw_s(txt){
     if(jw.window)
          jw.window.status = txt

     return true
}



function jw_setposition(toX,toY,l){
     if(!isjwin(l))
          return

     var jp = jwin.popups[l]
     var pW = jp.width, pH = jp.height, sTO = 0, sLO = 0

     var nsScroll = false

     nav.init(l)

     var nW = nav.width
     var nH = nav.height
     var nWh = nW/2
     var nHh = nH/2
     var sT = nav.scrollTop
     var sL = nav.scrollLeft

     if (jp.applyscrolloffsets && !(jp.markername || jp.anchormark || jp.markeroffset)){
          sTO = sT
          sLO = sL
     }

     if(jp.targetframe != self)
          nsScroll = true

     if(jp.showcenterscreen){
          jp.x = (nWh - (pW/2)) + sL
          jp.y = (nHh - (pH/2)) + sT
     }else{
          if(jp.fixedx != ''){
               jp.x = jp.fixedx + sLO
          }else{
               var h = jp.halign

               if(jp.halignauto){
                    if((toX - sL) > nWh)
                         h = LEFT
                    else
                         h = RIGHT
              }

               if(h==2 || h == 'center'){
		        jp.x = toX - (pW/2)
               }else if(h==3 || h =='right'){
                    if(nav.ns4up && !(nsScroll))
                         jp.x = toX + jp.offsetx
                    else
                         jp.x = (toX + sL) + jp.offsetx

                    if((jp.x + pW) > (sL + nW)){
                          jp.x = (sL + nW) - pW
                          if(jp.x < 0)
                               jp.x = 0
                    }
               }else{
                    if(nav.ns4up && !(nsScroll))
                         jp.x = toX - (pW + jp.offsetx)
                    else
                         jp.x = (toX + sL) - (pW + jp.offsetx)

                    if(jp.x < sL)
                         jp.x = sL
               }

               if(jp.snapx != ''){
                    jp.snapx = parseInt(jp.snapx)
                    var so = (jp.snapx == 0 ? 0 : jp.x % jp.snapx)
                    if(h == 1 || h == 'left')
                         jp.x -= so
                    else
                         jp.x += (jp.snapx - so)

                    if(jp.x < 0)
                         jp.x = 0
               }
          }

          if(jp.fixedy != ''){
               jp.y = jp.fixedy + sTO
          }else{
               var v = jp.valign

               if(jp.valignauto){
                    if((toY - sT) > nHh)
                         v = 1
                    else
                         v = 2

               }

               if(pH > 0 && v == 1 || v == 'above'){
                    if(nav.ns4up && !(nsScroll))
                         jp.y = toY - (pH + jp.offsety)
                    else
                         jp.y = (toY + sT) - (pH + jp.offsety)

                    if(jp.y < sT)
                         jp.y = sT
               }else{
                    if(nav.ns4up && !(nsScroll))
                         jp.y = toY + jp.offsety
                    else
                         jp.y = (toY + sT) + jp.offsety

               }

               if(jp.snapy != ''){
                    jp.snapy = parseInt(jp.snapy)
                    var so = (jp.snapy == 0 ? 0 : jp.y % jp.snapy)

                    if(pH > 0 && v == 1 || v == 'above')
                         jp.y -= so
                    else
                         jp.y += (jp.snapy - so)

                    if(jp.y < 0)
                         jp.y = 0
               }
         }
    }

    if(jp.dropshadow){
         var dy = parseInt(jp.dropshadowy)
         var dx = parseInt(jp.dropshadowx)
         if(dy < 0)
              jp.y -= dx
         if(dx < 0)
              jp.x -= dx
    }

    jp.setStat()
}


function jw_setmarker(l){
     var jp = jwin.popups[l], mn = jp.markername, mlyr = jw_getlyrbyid(mn, jw.window.document)
     var mkObj, of

     mlyr = mlyr || jw_getimgbyname(mn, jw.window.document)

     if(mlyr==null || mlyr==false){
          jw_errorhandler()
          return false
     }

     mkObj = mlyr

     if(document.layers){
	    if(typeof mlyr.length != 'undefined' && mlyr.length > 1){
               mkObj = mlyr[0]
	         jp.fixedx = mlyr[0].x + mlyr[1].pageX
	         jp.fixedy = mlyr[0].y + mlyr[1].pageY
          }else{
		   if(mlyr.toString().indexOf('Image') != -1){
		        jp.fixedx = mlyr.x
		        jp.fixedy = mlyr.y
               }else{
                    jp.fixedx = mlyr.pageX
                    jp.fixedy = mlyr.pageY
	         }
          }
     }else{
          jp.fixedx = jw_pageLocation(mlyr,'Left')
          jp.fixedy = jw_pageLocation(mlyr,'Top')
     }

     of = jw_getMarkerOffsets(mkObj, l)
     jp.fixedx += of[0]
     jp.fixedy += of[1]

     if(jp.markeroffset){
          mo = jp.markeroffset

          if(typeof mo == 'string' && mo.indexOf(',') != -1)
               mo = mo.split(',')

          if(mo[0])
               jp.fixedx += parseInt(mo[0])
          else
               alert("jwinError: Invalid markeroffset argument.")

          if(mo[1])
               jp.fixedy += parseInt(mo[1])
     }

     return true
}

function jw_getMarkerOffsets(mkObj, l){
     var tp = jwin.popups[l], mp = tp.anchormark.toUpperCase()
     var mW = mH = pW = pH = 0
     var of = [0,0]
     pW = tp.width
     pH = tp.height


     if(mkObj.toString().indexOf('Image') != -1){
          mW = mkObj.width
          mH = mkObj.height
     }else{
          mW = (nav.ns4) ? mkObj.clip.width : mkObj.offsetWidth
          mH = (nav.ns4) ? mkObj.clip.height : mkObj.offsetHeight
     }

     if(mp == 'UR')
          of = [mW - pW, 0]
     else if(mp == 'LL')
          of= [0, mH - pH]
     else if(mp == 'LR')
          of = [mW - pW, mH - pH]

     return of
}

function jw_pageLocation(o, t){
   var x = 0
   while(o.offsetParent != null && o.offsetParent.tagName != "BODY"){
      x += o['offset' + t]
      o = o.offsetParent
   }
   x += o['offset' + t]
   return x
}

function jw_callFunction(f){
     var s = ''
     if(typeof f == 'function'){
          return f()
     }else if(typeof f == 'string'){
          if(/\(/.test(f) && /\)/.test(f))
               return eval(f)
          else
               return eval(f + '()')
     }else{
          return s
     }
}

function jw_parseIt(p,args){
     var key, val

     if(!args)
          return false

     if(!p)
          var p = new cls_jwinpopup()

     for(var i = 0; i < args.length; i++){
          if(typeof args[i] == 'undefined'){
               i++
               continue
          }
          key = propArr[args[i]].toLowerCase()
          key = (key == 'function' ? 'Function' : key)
          val = args[++i]
          val = jw_getVarVal(val)
          p[key] = val
          continue
     }
     return p
}


function jw_parsetable(t,p){
     var start = 1,  pause = false, rp = 0, lp = 0
     var ch = wrd = prop = val = jwshow = ''

     if(!t)
          return false
     if(!p)
          var p = new cls_jwinpopup()

     for(var x = 0; x < t.length; x++){
          ch = t.substr(x,1)
          jwshow +=ch
          if(jwshow.indexOf(JWIN_OBJECT+'.show')>0 && pause == false){
               pause = true
               wrd+=ch
               jwshow=''
          }else if(pause == true){
               if(ch == '(')
                    lp++

               if(ch == ')')
                    rp++
               wrd+=ch

               if(lp == rp){
                    pause = false
                    jwshow =''
               }
          }else{
               if(ch==':'){
                    d = wrd.toLowerCase().trim()

                    d = (d == 'function' ? 'Function' : d)
                    if(typeof p[d] != 'undefined'){
                         prop = d
                         wrd = ''
                    }else{
                         wrd+=ch
                    }
               }else if(ch==';'){
                    c = t.indexOf(':',x+1)
                    prop = (prop == 'function' ? 'Function' : prop)
                    if(c > 0){
                         if(typeof p[prop] != 'undefined'){
                              p[prop] = jw_getVarVal(wrd.trim(), prop)
                              wrd = ''
                         }else{
                              wrd+=';'
                         }
                    }else{
                         p[prop]  = jw_getVarVal(wrd.trim(), prop)
                         wrd = ''
                    }
               }else{
                    wrd+=ch
               }
          }
     }
     return p
}


function jw_getVarVal(v, p){
     var typ = typeof v

     if(typ == 'object' || typ == 'boolean' || typ == 'number')
          return eval(v)
     else if(v.indexOf('[')== 0 && v.lastIndexOf(']') == (v.length-1))
          return eval(v)
     else if(v == 'true' || v == 'false' || p == 'targetframe')
          return eval(v)
     else if(jw_isInt(v))
          return parseInt(v)
     else
          return v


}

function jw_isInt(n){
     if(n.trim()=='')
          return false
     if(n.charAt(0)=="-")n = n.substr(1)
     for(var i = 0; i<n.length; i++)
          if(n.charAt(i) < "0" || n.charAt(i) > "9")
               return false
    return true
}


function jw_setStatus(){
     if(this.setstatus){
          if(this.statustext == '')
               this.statustext = this.text
          window.status = this.statustext
     }
}


function jw_closestick(id){
     var jp = jwin.popups[id]
     if(jp==null) return
     if(jwin.inmodalstate && !jp.modal)
          return

     if(jwin.inmodalstate){
          jwin.modalclosed = true
          jwin.inmodalstate = false
     }
     jw_clearevents(id)

     jp.playingtextarray = jp.playingcaptionarray = false
     jp.jwEvt_PlayArrayID = 0
     jp._textArrLen = jp._captionArrLen=0
     jp.styref.visibility = "hidden"
     jp.isvisible = false

     if(jp.handicap || jp.dropshadow){
          var jh = (jp.handicap) ? jp.handicap : jp.dropshadow
          jh = (jw_ns ? jh : jh.style)
          jh.visibility = 'hidden'
     }

     if(jp.delpopup)
          jw_delpopup(id)

}


function jw_errorhandler(){
     jwin.popups[jw.popup.id].jwError = true
     var jwc = jw_errorhandler.caller.toString()
     var f = 'function '
     if(jwc.indexOf(f + 'jw_show') >= 0)
          alert('jwinError: Layer ' + jw.window.name + '.' + jw.popup.id + ' not found.')
     else if(jwc.indexOf(f + 'jw_setmarker') >= 0)
          alert('jwinError: Marker ' + jw.window.name + '.' + jw.popup.markername + ' not found.')
     else
          alert('jwinError: ' + jwc)


     if(jw.popup.delpopup)
          jw_delpopup(jw.popup.id)


}


function jw_trim(){
    var s1 = this.replace(/(^ *)/,"")
    var ret = s1.replace(/( *)$/,"")
    return ret
}
String.prototype.trim = jw_trim


function jw_isdelayeffect(l){
     for(var x = 0; x < jwin.popupscount; x++){
          if(isjwin(x)){
               if(jwin.popups[jwin.popups[x].id].jwEvt_DelayOpenCloseID > 0){
                    if(l == jwin.popups[x].id)
                         return true
               }
          }
     }
     return false
}


function jw_isplayingtextarray(l){
     for(var x = 0; x < jwin.popupscount; x++){
          if(isjwin(x)){
               if(jwin.popups[jwin.popups[x].id].playingtextarray){
                    if(l == jwin.popups[x].id)
                         return true
               }
          }
     }
     return false
}


function jw_processArrays(l){
     if(isjwin(l)){
          var jshow = false
          var jp = jwin.popups[l]

          if(jp.playingtextarray){
               if(jp._textarrcount < jp._textarrlen){
                    if(jp.arrayinterval > 0){
                         jp.writetext = jp._textarray[jp._textarrcount]
                         jp._textarrcount++
                         jshow = true
                    }
               }else{
                    jp.playingtextarray = false
                    jp._textarrlen = 0
                    if(!jp.playingcaptionarray)
                         jshow = false
               }
          }

          if(jp.playingcaptionarray){
               if(jp._captionarrcount < jp._captionarrlen){
                    if(jp.arrayinterval > 0){
                         jp.captiontext = jp._captionarray[jp._captionarrcount]
                         jp._captionarrcount++
                         jshow = true
                    }
               }else{
                    jp.playingcaptionarray = false
                    jp._captionarrlen = 0
                    if(!jp.playingtextarray)
                         jshow = false
               }
          }

          if(jshow){
               jw_write(l)
               jp.jwEvt_PlayArrayID = setTimeout('jw_processArrays("'+ l +'")', jp.arrayinterval)
               jp.statustext = ''
               jp.setStat(jp.writetext)
          }

          if(jp.arrayclose){
               if(!jp.playingtextarray){
                    if(!jp.playingcaptionarray)
                         jw_hideme(l)
               }
          }
     }
}

function cls_jwinpopup(){
}
var p = cls_jwinpopup.prototype
p.getSimple          = jw_getSimplePopup
p.getCaption         = jw_getCaptionPopup
p.getClosingTableDef = jw_getClosingTableDefVal
p.getPaddedText      = jw_getPaddedTextContent
p.getHR              = jw_getHRule
p.getPopW            = jw_getPopWidth
p.getPopH            = jw_getPopHeight
p.getTPadL           = jw_getTextPadL
p.getTPadR           = jw_getTextPadR
p.getTPadT           = jw_getTextPadT
p.getTPadB           = jw_getTextPadB
p.getTPad            = jw_getTextPad
p.setCIcon           = jw_setCapIcon
p.setStat            = jw_setStatus

var p = cls_jwinpopup.prototype
p.cls_name='cls_table'
p.styref = p.layref = new Object
p.visible = p.delpopup = true
p.border = p.style = 1
p.bordercolor = '#333399'
p.bgcolor='#FFFFFF'
p.textfont=JWIN_DEF_FONT
p.textcolor = p.dropshadowcolor = '#000000'
p.dropshadowx = p.dropshadowy = 5
p.textsize='2'
p.text = 'A JWIN popup'
p.Function = null
p.textcellpadding = p.textcellspacing = p.textborder = p.bordercellpadding = p.bordercellspacing = p.delayinterval = p.textpadbottom = p.textpadright = p.textpadtop = p.textpadleft = p.arrayinterval = 0
p.id = p.code = p.width = p.height = p.background = p.captiontext = p.textbordercolor = p.captionicon = p.closetext = p.closetaginsert = p.markername = p.statustext = p.fixedx = p.fixedy = p.snapx = p.snapy = p.markeroffset = p.writetext = p.closeimage = p.divclass = p.textclass = p.captionclass = p.closeclass = p.handicap = p.dropshadow = p.anchormark = ''
p.captiontextcolor = '#FFFFFF'
p.captiontextfont = JWIN_DEF_FONT
p.captiontextsize = p.closetextsize = '2'
p.captionbgcolor = p.captiontextbordercolor = '#333399'
p.captiontextborder = p.captioncellpadding = p.captioncellspacing = p.jwEvt_MouseOverID = p.jwEvt_DelayOpenCloseID = p.jwEvt_PlayArrayID = 0
p.closetextcolor = '#9999FF'
p.closetextfont = JWIN_DEF_FONT
p.closeonclick = p.playcaptionarray = p.playingcaptionarray = p.playtextarray = p.arrayclose = p.playingtextarray = p.captiontextseparator = p.showcenterscreen = p.stickaround = p.followmouse = p.modal = p.autowidth = p.autoheight = p.textonly = p.captiontextonly = p.valignauto = p.halignauto = p.centertext = p.centercaptiontext = p.setstatus = p.mouseover = p.autozindex = p.closeonframeout = p.isvisible = p.jwError = p.capturemouseevents = p.debug = p.classes = p.applyscrolloffsets = false
p.targetframe = self
p.valign = p.delayevent = 2
p.halign = 3
p.offsetx = p.offsety = 10
p.x = p.y = p._textarrlen = p._textarrcount = p._captionarrlen = p._captionarrcount = 0
p._textarray = p._captionarray = ''


function jw_getPopWidth(){
     return (this.width) ? ' width="' + this.width + '"' : ''
}


function jw_getPopHeight(){
     return (this.height) ? ' height="' + this.height + '"' : ''
}


function jw_getSimplePopup(){
     if(this.writetext == '')
        this.writetext = this.text

     var d = this.text
     var t = '<table width="100%" border="' + this.textborder + '" bordercolor="' + this.textbordercolor + '" cellpadding="' + this.textcellpadding + '" cellspacing="' + this.textcellspacing + '" bgcolor="' + this.bgcolor + '"' + this.getPopH() +' background="' + this.background + '"><tr><td>' + this.getPaddedText(this.writetext) + '</td></tr></table>'

     if(this.playtextarray && this.playingtextarray==false && d != null && typeof d == 'object'){
          this._textarrcount = 0

          if(this._textarray == ''){
               jwt = jw_getarray(this.writetext)
               this._textarray = jwt
          }

          this.writetext = this._textarray[this._textarrcount]
          this._textarrcount++
          if(this._textarrlen == 0)
               this._textarrlen = this._textarray.length

          this.playingtextarray = true
          this.jwEvt_PlayArrayID = setTimeout('jw_processArrays("'+ this.id + '")', this.arrayinterval)
     }

     if(this.textonly){
          return this.writetext
     }else{
          if(this.background != ''){
               var jw_bgpic = (nav.ie4up) ? this.background:''
	         return '<table' + this.getPopW() + this.getPopH() + ' border="0" cellpadding="0" cellspacing="0" background="' + jw_bgpic + '"><tr><td>' + this.getPaddedText(this.writetext) + '</td></tr></table>'
          }else{
               if(this.classes){
                    if(!jw_ns && this.divclass)
                         this.layref.className = this.divclass

                    var s0 = '<table' + this.getPopW() + this.getPopH() + ' border="0" cellpadding="' + this.textcellpadding + '" cellspacing="' + this.textcellspacing + '"><tr><td' + ' class = "' + this.textclass + '">' + this.text + '</td></tr></table>'
                    if(jw_ns)
                         s0 = '<div class="' + this.divclass + '">' + s0 + '</div>'

                    return s0
               }else{
                    return '<table' + this.getPopW() + this.getPopH() + ' border="' + this.border + '" bordercolor="' + this.bordercolor + '" cellpadding="' + this.bordercellpadding + '" cellspacing="' + this.bordercellspacing + '" bgcolor="' + this.bgcolor + '"><tr><td>' + this.getPaddedText(this.writetext) + '</td></tr></table>'
               }
          }
     }
}


function jw_getarray(t){
     var a = new Array
     if(typeof t == 'string'){
          var cm = t.replace(/\/,/g,"[jw_com]")
          var cm2 = cm.split(',')
          for(var x = 0; x < cm2.length; x++)
               a[x] = cm2[x].replace(/\[jw_com\]/g,",")
          return a
     }else{
          return t
     }
}


function jw_getCaptionPopup(){
     var processarray = false, jwt = new Array, d

     if(this.writetext == '')
        this.writetext = this.text

     d = this.text
     if(this.playtextarray && this.playingtextarray==false && this.playingcaptionarray == false &&  d != null && typeof d == 'object'){
         jw_clearevents(this.id)
         this._textarrcount = 0

         if(this._textarray == ''){
              jwt = jw_getarray(this.writetext)
              this._textarray = jwt
         }

         this.writetext = this._textarray[this._textarrcount]
         this._textarrcount++
         if(this._textarrlen == 0)
              this._textarrlen = this._textarray.length

         processarray = true
     }

     d = this.captiontext
     if(this.playcaptionarray && this.playingcaptionarray == false && this.playingtextarray == false && d != null && typeof d == 'object'){
          jw_clearevents(this.id)
          this._captionarrcount = 0

          if(this._captionarray == ''){
               jwt = jw_getarray(this.captiontext)
               this._captionarray = jwt
          }

          this.captiontext = this._captionarray[this._captionarrcount]
          this._captionarrcount++
          if(this._captionarrlen == 0)
               this._captionarrlen = this._captionarray.length

          processarray = true
     }

     if(processarray){
          this.jwEvt_PlayArrayID = setTimeout('jw_processArrays("'+ this.id + '")', this.arrayinterval)
          this.playingtextarray = true
          this.playingcaptionarray = true
     }

     if(this.captionicon!='')
          this.setCIcon(this.captionicon)


      var fs1, s0, s1, s2, s3, s5, s6, ret

     s0 = this.captiontextsize + ''

     if(this.classes){
          if(!jw_ns && this.divclass)
               this.layref.className = this.divclass

          s1 = s2 = '<table' + this.getPopW() + this.getPopH() + ' border="0" cellpadding="0" cellspacing="0"><tr><td>'
          s3 = '<table width="100%" border="0" cellpadding="' + this.captioncellpadding + '" cellspacing="' + this.captioncellspacing + '"><tr><td><table width="100%" border="0" cellpadding="0" cellspacing="0"><tr><td class="' + this.captionclass + '">' + this.captionicon
          s4 = s3 + this.captiontext + '</td>' + this.getClosingTableDef(this.closeclass) + '</tr></table></td></tr></table>'
          s5 = '<table width="100%" border="0" ' + this.getPopH() + ' cellpadding="' + this.textcellpadding + '" cellspacing="' + this.textcellspacing + '"><tr><td class="' + this.textclass + '">' + this.writetext + '</td></tr></table>'
     }
     else{
          s1 = '<table' + this.getPopW() + this.getPopH() + ' border="' + this.border + '" bordercolor="' + this.bordercolor + '" cellpadding="' + this.bordercellpadding + '" cellspacing="' + this.bordercellspacing + '"  bgcolor="' + this.bgcolor + '"><tr><td>'
          s2 = '<table' + this.getPopW() + this.getPopH() + ' border="0" cellpadding="' + this.bordercellpadding + '" cellspacing="' + this.bordercellspacing + '"><tr><td>'
          s3 = '<table width="100%" border="' + this.captiontextborder + '" bordercolor="' + this.captiontextbordercolor + '"  cellpadding="' + this.captioncellpadding + '" cellspacing="' + this.captioncellspacing + '" bgcolor="' + this.captionbgcolor + '"><tr><td><table width="100%" border="0" cellpadding="0" cellspacing="0"><tr><td align="left">' + this.captionicon +jw_getCenterText(this.centercaptiontext,0)

          if(s0.indexOf("px") != -1)
               fs1 = '<font style="font-family: ' + this.captiontextfont + '; color: ' + this.captiontextcolor + '; font-size: ' + this.captiontextsize + '">'
          else
               fs1 = '<font color="' + this.captiontextcolor + '" face="' + this.captiontextfont + '" size="' + this.captiontextsize + '">'

          s4 = s3 + fs1 + this.captiontext +'</font>'+jw_getCenterText(this.centercaptiontext,1) +'</td>' + this.getClosingTableDef() + '</tr></table></td></tr></table>' + this.getHR()
          s5 = '<table width="100%" border="' + this.textborder + '" bordercolor="' + this.textbordercolor + '" cellpadding="' + this.textcellpadding + '" cellspacing="' + this.textcellspacing + '" bgcolor="' + this.bgcolor + '"' + this.getPopH() +' background="' + this.background + '"><tr><td>' + this.getPaddedText(this.writetext) + '</td></tr></table>'
     }

     s6 = '</td></tr></table>'


     if(this.captiontextonly)
          ret = s2 + this.captiontext
     else
          ret = s1 + s4

     if(this.textonly)
          ret += this.writetext
     else
          ret += s5

     ret += s6

     if(jw_ns && this.classes)
          ret = '<div class="'+ this.divclass + '">' + ret + '</div>'

     return ret

}


function jw_getTextPadL(){return (this.textpadleft) ? ' width="'+ this.textpadleft + '"' : ''}
function jw_getTextPadR(){return (this.textpadright) ? ' width="' + this.textpadright + '"' : ''}
function jw_getTextPadT(){return (this.textpadtop) ? ' height="' + this.textpadtop + '"' : ''}
function jw_getTextPadB(){return (this.textpadbottom) ? ' height="' + this.textpadbottom + '"' : ''}
function jw_getTextPad(){ return (this.width) ? ' width="' + (this.width-this.textpadleft-this.textpadright)+ '"' : ''}


function jw_getPaddedTextContent(text){
    var fs1, s0 = this.textsize + '', s1 = '<table border="0" cellpadding="0" cellspacing="0"><tr><td colspan="3"' + this.getTPadT()+ '></td></tr><tr><td' + this.getTPadL()+ '></td><td'+ ((this.autowidth==true && nav.ie4up)? ' width="100%" ': this.getTPad())+ '>'

    if(s0.indexOf("px") != -1)
         fs1 = '<font style="font-family:  ' + this.textfont + '; color: ' + this.textcolor + '; font-size: ' + this.textsize + '">'
    else
         fs1 = '<font color="' + this.textcolor + '" face="' + this.textfont + '" size="' + this.textsize + '">'

    return s1 +jw_getCenterText(this.centertext,0) + fs1 + text + '</font>' +jw_getCenterText(this.centertext,1) + '</td><td' + this.getTPadR() + '></td></tr> <tr><td colspan="3"' + this.getTPadB() + '></td></tr></table>'
}


function jw_getCenterText(a,e){
     if(a==false)
          return ''

     if(e)
          return '</div>'
     else
          return '<div align="center">'
}


function jw_getHRule(){
     return (this.captiontextseparator) ? '<hr>' : ''
}

function jw_getcallingframe(){
     var fr = 'parent.frames'
     var efr = eval(fr)
     var fl = efr.length

     for(var x = 0; x < fl; x++){
          var lfr = efr[x]
          if(lfr == self)
               return fr + '.' + lfr.name
     }
}

function jw_getClosingTableDefVal(cc){
     var om = 'onmouseover', cti='', fs1, s0, s1
     var closing = (this.closetext || this.stickaround || this.modal && this.closeimage != ''  ? (this.closetext == '' ? 'Close' : this.closetext) : this.setCIcon(this.closeimage))
     var cs = 'jw_closestick(\''+ this.id + '\')'

     if(this.targetframe != self){
          jwfrm = this.targetframe
          var tFrm = jw_getFrameRef(top.frames)
          jwfrm = self
          var sFrm = jw_getFrameRef(top.frames)

          if(sFrm.length == tFrm.length){
               l = tFrm.lastIndexOf('[')
               if(l){
                    while(sFrm.substring(0,l) != tFrm.substring(0,l))
                         l = tFrm.lastIndexOf('[',l-1)
                    tFrm = tFrm.substr(l)
                    sFrm = sFrm.substr(l)
               }
          }


          var cnt = 0, p = '', str = tFrm, k
          while((k = str.lastIndexOf('[')) != -1){
               cnt++
               str = str.substring(0,k)
          }

          for(var i=0; i<cnt; i++)
               p = p + 'parent.'

               cs = p + 'frames' + sFrm + '.' + cs
     }


     if(this.closeonclick)
          om = 'onclick'

     if(this.closetaginsert != '')
         cti = this.closetaginsert

    if(closing == ''){
          return ''
     }else{
          if(cc){
               s1 = '<td class="' + cc + '"><a href="javascript:void(0);" ' + om + '="' + cs + '">'
          }else{
               s0 = this.closetextsize + ''

               //s1 = '<td align="right"><a href="javascript:void(0);" ' + cti + ' '+ om + '="'+ cs + '">'

               /**
                * visual improvement for LessonBuilder
                */
               s1 = '<td align="right" valign="top"><a href="javascript:void(0);" ' + cti + ' '+ om + '="'+ cs + '">'

               if(!this.closeimage){
                    if(s0.indexOf("px") != -1)
                         fs1 = '<font style="font-family: ' + this.closetextfont + '; color: ' + this.closetextcolor + '; font-size: ' + this.closetextsize + '">'
                    else
                         fs1 = '<font color="' + this.closetextcolor + '" face="' + this.closetextfont + '" size="' + this.closetextsize + '">'

                   closing = fs1 + closing + '</font>'
               }
          }
          return s1 + closing + '</a></td>'
     }
}


function jw_setCapIcon(c){
     if(c && c.indexOf("<img ") == -1)
         return this.captionicon = '<img src="'+ c +'" border="0">'
     else
         return this.captionicon = ''
}


function jwinbrowser(){
    this.agt = navigator.userAgent.toLowerCase()
    this.major = parseInt(navigator.appVersion)
    this.minor = parseFloat(navigator.appVersion)
    this.ns  = ((this.agt.indexOf('mozilla')!=-1) && (this.agt.indexOf('spoofer')==-1) && (this.agt.indexOf('compatible') == -1) && (this.agt.indexOf('opera')==-1) && (this.agt.indexOf('webtv')==-1) && (this.agt.indexOf('hotjava')==-1))
    this.ns2 = (this.ns && (this.major == 2))
    this.ns3 = (this.ns && (this.major == 3))
    this.ns4 = (this.ns && (this.major == 4))
    this.ns4up = (this.ns && (this.major >= 4))
    this.nsonly = (this.ns && ((this.agt.indexOf(";nav") != -1) || (this.agt.indexOf("; nav") != -1)) )
    this.ns6 = (this.ns && (this.major == 5))
    this.ns6up = (this.ns && (this.major >= 5))
    this.gecko = (this.agt.indexOf('gecko') != -1)
    this.ie     = ((this.agt.indexOf("msie") != -1) && (this.agt.indexOf("opera") == -1))
    this.ie3    = (this.ie && (this.major < 4))
    this.ie4    = (this.ie && (this.major == 4) && (this.agt.indexOf("msie 5")==-1) )
    this.ie4up  = (this.ie && (this.major >= 4))
    this.ie5    = (this.ie && (this.major == 4) && (this.agt.indexOf("msie 5.0")!=-1) )
    this.ie5_5  = (this.ie && (this.major == 4) && (this.agt.indexOf("msie 5.5") !=-1))
    this.ie5up  = (this.ie && !this.ie3 && !this.ie4)
    this.ie5_5up =(this.ie && !this.ie3 && !this.ie4 && !this.ie5)
    this.opera = (this.agt.indexOf("opera") != -1)
    this.opera2 = (this.agt.indexOf("opera 2") != -1 || this.agt.indexOf("opera/2") != -1)
    this.opera3 = (this.agt.indexOf("opera 3") != -1 || this.agt.indexOf("opera/3") != -1)
    this.opera4 = (this.agt.indexOf("opera 4") != -1 || this.agt.indexOf("opera/4") != -1)
    this.opera5 = (this.agt.indexOf("opera 5") != -1 || this.agt.indexOf("opera/5") != -1)
    this.opera5up = (this.opera && !this.opera2 && !this.opera3 && !this.opera4)
    this.getWidth = jwinbrowser_getClientWidth
    this.getHeight = jwinbrowser_getClientHeight
    this.getScrollTop = jwinbrowser_getClientScrollTop
    this.getScrollLeft = jwinbrowser_getClientScrollLeft
    this.init = jwinbrowser_init
}

function jwinbrowser_init(l){
    l = jwin.popups[l]
    this.getWidth(l)
    this.getHeight(l)
    this.getScrollTop(l)
    this.getScrollLeft(l)
}


function jwinbrowser_getClientWidth(l){
     if(l.targetframe != self)
          return this.width = (this.ie4up) ? eval('l.targetframe.' + docRoot + '.clientWidth') : l.targetframe.window.innerWidth
     else
          return this.width = (this.ie4up) ? eval(docRoot + '.clientWidth') : window.innerWidth
}


function jwinbrowser_getClientHeight(l){
     if(l.targetframe != self)
          return this.height = (this.ie4up) ?  eval('l.targetframe.' + docRoot + '.clientHeight') : l.targetframe.window.innerHeight
     else
          return this.height = (this.ie4up) ?  eval(docRoot + '.clientHeight') : window.innerHeight
}


function jwinbrowser_getClientScrollTop(l){
     if(l.targetframe != self)
          return this.scrollTop = (this.ie4up) ?  eval('l.targetframe.' + docRoot + '.scrollTop') : l.targetframe.window.pageYOffset
     else
          return this.scrollTop = (this.ie4up) ?  eval(docRoot + '.scrollTop') : window.pageYOffset
}


function jwinbrowser_getClientScrollLeft(l){
     if(l.targetframe != self)
          return this.scrollLeft = (this.ie4up) ?  eval('l.targetframe.' + docRoot + '.scrollLeft') : l.targetframe.window.pageXOffset
     else
          return this.scrollLeft = (this.ie4up) ?  eval(docRoot + '.scrollLeft') : window.pageXOffset
}



var jw_ie = (document.all) ? true : false
var jw_ns = (navigator.appName == "Netscape" && parseInt(navigator.appVersion) == 4)
var nav = new jwinbrowser()
var jpx = jw_ns ? '':'px'
var docRoot = 'document.body'
if(jw_ie && document.compatMode && document.compatMode == 'CSS1Compat')
     docRoot = 'document.documentElement'



if(!nav.ie4up && !nav.ns4up && !nav.opera5up){
     jwp.show = jw_null
     jwp.hide = jw_null
}else{
     jw_setmousemove()
}

function jw_null(){}

function jw_setmousemove(){
     var fn, func, re = /function[ ]+(\w+)\(/
     if(document.onmousemove || window.onmousemove){
          if(document.onmousemove)
               func = document
          else if(window.onmousemove)
               func = window
          fn = func.onmousemove.toString().match(re)
          if(fn[1] == 'jw_mousehandler')
               return
          var str = 'jw_mousehandler(e); ' + fn[1] + '(e)';
          func.onmousemove = new Function('e',str)
     }else{
          document.onmousemove = jw_mousehandler
          func =  document
     }
     if(nav.ns4)
          func.captureEvents(Event.MOUSEMOVE)
 }

function jw_mousehandler(e){
     var e = (nav.ns4up || nav.ns6up) ? e : event
     var jc = jw_scr
     if(nav.ns4){
          jc.o_X = e.pageX - self.pageXOffset
          jc.o_Y = e.pageY - self.pageYOffset
     }else{
          jc.o_X = e.clientX
          jc.o_Y = e.clientY
     }

     if(nav.ns4up || nav.ns6up){
          jc.o_W = self.innerWidth - 2
          jc.o_H = self.innerHeight - 2
     }else{
              jc.o_W = eval('self.' + docRoot + '.offsetWidth - 4')
                   jc.o_H = eval('self.' + docRoot + '.offsetHeight - 4')
           }

     if(nav.ns4up || nav.ns6up){
          jc.m_X = e.pageX
          jc.m_Y = e.pageY
     }else if(nav.ie4up){
          jc.m_X = e.x
          jc.m_Y = e.y
     }else if(nav.ie5up){
  jc.m_X = eval('e.x+' + docRoot + '.scrollLeft')
          jc.m_Y = eval('e.y+' + docRoot + '.scrollTop')
   }else if(nav.opera){
          jc.m_X = e.clientX
          jc.m_Y = e.clientY
     }
     jc.mouseout = (jc.o_X < 2 || jc.o_X > jc.o_W ||jc.o_Y < 2 || jc.o_Y > jc.o_H)

     for(var t = 0; t < jwin.popupscount; t++){
        if(!isjwin(t) || jwin.popups[t] == null)
             continue
        var jp = jwin.popups[t]
        if(jwin.popups[jp.id] != null){
             if(jwin.popups[jp.id].visible && jwin.popups[jp.id].closeonframeout && jc.mouseout)
                  jw_closestick(jp.id)
        }
     }

     if(typeof jw != 'undefined'){
          if(typeof jw.popup != 'undefined'){
               if(jw.popup.followmouse){
                    if(jw.popup.styref.visibility!=null){
                         if(jw.popup.styref.visibility.indexOf('hid') == -1)
                              jw_move()
                    }
               }
          }
     }
}


var propArr = new Array, _jwp = new cls_jwinpopup(), pr = 0
for(prop in _jwp){
     propArr[pr++] =((prop.charAt(0) == '_' || prop.indexOf('jwE') != -1 || typeof _jwp[prop] == 'function') ? prop : prop.toUpperCase())
}
for(var i = 0; i < propArr.length; i++){
    eval('var ' + propArr[i] + '=' + i)
}

var jwfrm
function jw_getFrameRef(f){
     var r = ''
     for(var i = 0; i < f.length; i++){
          if(f[i].length > 0){
               r = jw_getFrameRef(f[i])
               if(r == '')
                    continue
          }else if(f[i] != jwfrm){
               continue
          }
          r = '[' + i + ']' + r
          break
        }
     return r
}

function jw_clipbackdrop(l){
     var jp = jwin.popups[l]
     var jh = jp.handicap
     if(jw_ns){
          jh.clip.width = jp.layref.clip.width
          jh.clip.height = jp.layref.clip.height
     }else{
          jh.style.clip = 'rect(0px ' + jp.layref.offsetWidth + 'px ' + jp.layref.offsetHeight + 'px 0px)'
     }
}

function jw_nsPixel(){
     if(nav.ns4)
          return 2
     if(nav.ns6up)
          return 1
     else
          return 0
}

function jw_getdropshadow(l){
     var tp = jwin.popups[l]
     var ostr = '<table bgcolor="' + tp.dropshadowcolor + '" width="' + (parseInt(tp.width)+jw_nsPixel()) + '" height="' + (parseInt(tp.height)+jw_nsPixel()) + '"><tr><td>&nbsp;</td></tr></table>'

     if(document.layers){
          tp.dropshadow.document.open()
          tp.dropshadow.document.write(ostr)
          tp.dropshadow.document.close()
     }else{
          tp.dropshadow.innerHTML = ostr
     }
}



// these vars will be phased out eventually
var JWIN_POPUP_STYLESIMPLE = 1, JWIN_POPUP_STYLECAPTION = 2, JWIN_HALIGN_LEFT = 1, JWIN_HALIGN_CENTER = 2, JWIN_HALIGN_RIGHT = 3,JWIN_VALIGN_ABOVE = 1, JWIN_VALIGN_BELOW = 2, JWIN_DELAY_OPEN = 1, JWIN_DELAY_CLOSE = 2
