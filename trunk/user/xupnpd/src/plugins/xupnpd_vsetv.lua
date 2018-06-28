-- Copyright (C) 2015 Sergi Adamchuk
-- sergi79@ukr.net
-- http://solvek.com
-- Description: Watching content of site vsetv.net
-- Depends on: HLS plugin

function vsetv_updatefeed(feed,friendly_name)
    local rc=false

    local feed_name='vsetv_'..string.gsub(feed,'/','_')
    local feed_m3u_path=cfg.feeds_path..feed_name..'.m3u'
    local tmp_m3u_path=cfg.tmp_path..feed_name..'.m3u'

    local dfd=io.open(tmp_m3u_path,'w+')
	if dfd then
	 dfd:write('#EXTM3U name=\"',friendly_name or feed_name,'\" plugin=vsetv\n')
	 dfd:write('#EXTINF:0,Try me\nhttp://vsetv.net/piksel.html\n')   

	 dfd:close()

	    if util.md5(tmp_m3u_path)~=util.md5(feed_m3u_path) then
		if os.execute(string.format('mv %s %s',tmp_m3u_path,feed_m3u_path))==0 then
		    if cfg.debug>0 then print('Vsetv feed \''..feed_name..'\' updated') end
		    rc=true
		end
	    else
		util.unlink(tmp_m3u_path)
	    end
	end

    return rc
end

function vsetv_sendurl(vsetv_url,range)
  --print('VseTV Sending url')
   -- print('Sending real url for '..vsetv_url)
  
    local url=nil

    if plugin_sendurl_from_cache(vsetv_url,range) then return end

    local clip_page=plugin_download(vsetv_url)
    local url = nil

    if clip_page then
	--print('Page is downloaded')
	url=string.match(clip_page,'m=video&file=([^"]+)"')
	--print('Extracted url: '..url)
        clip_page=nil
    else
        if cfg.debug>0 then print('Vsetv clip is not found') end
    end

    if url then
        if cfg.debug>0 then print('Vsetv Real URL: '..url) end
--	http.sendurl(url,1,range)
--        plugin_sendurl(vsetv_url,url,range)
	plugins.hls.sendurl(url,range)
    else
        if cfg.debug>0 then print('Vsetv Real URL is not found') end

        plugin_sendfile('www/corrupted.mp4')
    end
end

plugins['vsetv']={}
plugins.vsetv.name="VseTv"
plugins.vsetv.desc="<i>No parameters</i>"
plugins.vsetv.sendurl=vsetv_sendurl
plugins.vsetv.updatefeed=vsetv_updatefeed
