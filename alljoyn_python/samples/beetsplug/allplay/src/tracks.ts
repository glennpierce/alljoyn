import {inject, Lazy, autoinject} from 'aurelia-framework';
import {HttpClient} from 'aurelia-fetch-client';
import {Router} from 'aurelia-router';
import {AllPlay, ITrack} from './allplay';


@inject(AllPlay, Router)
export class Tracks {
  heading : string = 'Tracks';
  tracks : Array<ITrack> = [];
  pageTracks : Array<ITrack> = [];
  activePage : number = 1;
  numberOfPages : number = 1;
  tracksPerPage : number = 25;
  searchText : string = "";

  constructor(private allplay: AllPlay, private router: Router) {

  }

  async activate(): Promise<void> {
    this.tracks = await this.allplay.getTracks();
    this.numberOfPages = this.tracks.length / this.tracksPerPage;
  }

  private match(search : string, item: any) : boolean {
        let lcase_search = search.toLowerCase();
        if((item['title'].toLowerCase().indexOf(lcase_search) > -1) ||
        (item['artist'].toLowerCase().indexOf(lcase_search) > -1) ||
        (item['album'].toLowerCase().indexOf(lcase_search) > -1)) {
            return true;
        }
        return false;
  }

  onPageChanged(e) {
    let pageNumber = e.detail;
    let filteredItems = this.tracks.slice();

    if (this.searchText !== undefined && this.searchText !== "")  {
        filteredItems = this.tracks.filter((item) => this.match(this.searchText, item)); 
    }

    let start : number = this.tracksPerPage * (pageNumber - 1);
    filteredItems = filteredItems.slice(start, start + this.tracksPerPage); 
    this.pageTracks = filteredItems;
  }

  addToQueue(event: any, track: ITrack) {
    this.allplay.addToQueue(track);
  }

  gotoTrackEdit(event: any, track: ITrack) {
    this.router.navigateToRoute('track-edit', { id: track.id });
    event.preventDefault();
  }

  playTrack(event: any, track: ITrack) {
    this.allplay.playTrack(track);
  	return true;
  }
}
